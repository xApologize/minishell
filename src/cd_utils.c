#include "../include/minishell.h"

//same as ft_strjoinfree. joins 2 strings and
//frees the once given as first argument
// static char	*ft_pwdjoinfree(const char *s1, const char *s2)
// {
// 	int		s1len;
// 	int		s2len;
// 	int		i;
// 	char	*newstring;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	s1len = ft_strlen((char *)s1);
// 	s2len = ft_strlen((char *)s2);
// 	i = s1len;
// 	newstring = ft_calloc((s1len + s2len + 1), sizeof(char));
// 	if (!newstring)
// 		return (NULL);
// 	newstring = ft_memcpy(newstring, s1, s1len);
// 	while (i < s1len + s2len)
// 	{
// 		newstring[i] = s2[i - s1len];
// 		i++;
// 	}
// 	free((void *) s2);
// 	return (newstring);
// }

//searches the environment variables for
//the OLDPWD. Returns the index if found, -1 if not
int	find_oldpwd(void)
{
	int		index;
	char	**envp_split;

	index = -1;
	while (g_envp_copy[++index])
	{
		envp_split = ft_split(g_envp_copy[index], '=');
		if (ft_strcmp("OLDPWD", envp_split[0]) == 0)
		{
			free_the_pp(envp_split);
			return (index);
		}
		free_the_pp(envp_split);
	}
	return (-1);
}

//same as find_oldpwd. Returns the index if found, -1 if not
int	find_pwd(void)
{
	int		index;
	char	**envp_split;

	index = -1;
	while (g_envp_copy[++index])
	{
		envp_split = ft_split(g_envp_copy[index], '=');
		if (ft_strcmp("PWD", envp_split[0]) == 0)
		{
			free_the_pp(envp_split);
			return (index);
		}
		free_the_pp(envp_split);
	}
	return (-1);
}

//updates OLDPWD and PWD environment variables according to
//the new path given when using cd. If either OLDPWD or
//PWD are unset does nothing
//if PWD and OLDPWD still exist, both updated. if PWD unset, no longer updated but OLDPWD updated. If OLDPWD unset gets recreated

void	change_pwd(int index)
{
	char	*newpath;

	newpath = NULL;
	if (index != -1)
	{
		newpath = getcwd(newpath, 0);
		free(g_envp_copy[index]);
		g_envp_copy[index] = ft_strjoin("PWD=", newpath);
		free(newpath);
	}
}

void	change_oldpwd(int index, char *home)
{
	char	*oldpwd;

	oldpwd = NULL;
	if (index != -1)
	{
		free(g_envp_copy[index]);
		g_envp_copy[index] = ft_strjoin("OLDPWD=", home);
	}
	else
	{
		oldpwd = ft_strjoin("OLDPWD=", home);
		addtoenv(oldpwd);
		free(oldpwd);
	}
}

void	update_pwd(char *home)
{
	int	index_pwd;
	int	index_oldpwd;

	index_pwd = find_pwd();
	index_oldpwd = find_oldpwd();
	change_pwd(index_pwd);
	change_oldpwd(index_oldpwd, home);
	if (home)
		free(home);
}

//changes current directory based on argument
//given. Also updates PWD and OLDPWD.
void	handle_cd(t_cmd *cmd)
{
	int		res;
	char	*home;

	home = NULL;
	if (cmd->argv[1] == NULL)
	{
		home = get_home();
		res = chdir(home);
		if (home)
			free(home);
		set_exit_code(0);
	}
	else
	{
		home = getcwd(home, 0);
		res = chdir(cmd->argv[1]);
		set_exit_code(0);
	}
	update_pwd(home);
	if (res == -1)
	{
		dprintf(STDERR_FILENO, "minicougar: cd: \
		%s: %s\n", strerror(errno), cmd->argv[1]);
		set_exit_code(1);
	}
}
