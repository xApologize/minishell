#include "../include/minishell.h"

//same as ft_strjoinfree. joins 2 strings and
//frees the once given as first argument
static char	*ft_pwdjoinfree(const char *s1, const char *s2)
{
	int		s1len;
	int		s2len;
	int		i;
	char	*newstring;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	i = s1len;
	newstring = ft_calloc((s1len + s2len + 1), sizeof(char));
	if (!newstring)
		return (NULL);
	newstring = ft_memcpy(newstring, s1, s1len);
	while (i < s1len + s2len)
	{
		newstring[i] = s2[i - s1len];
		i++;
	}
	free((void *) s2);
	return (newstring);
}

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

void	update_pwd(void)
{
	int	index_pwd;
	int index_oldpwd;

	index_pwd = find_pwd();
	index_oldpwd = find_oldpwd();
	if (index_pwd != 1)
		change_pwd();
	if (index_oldpwd != 1)
		change_oldpwd();
}
// void	update_pwd(void)
// {
// 	int		index_pwd;
// 	int		index_oldpwd;
// 	char	*new_path;
// 	char	**old_path;

// 	new_path = NULL;
// 	new_path = getcwd(new_path, 0);
// 	index_oldpwd = find_oldpwd();
// 	index_pwd = find_pwd();
// 	if (index_pwd != -1)
// 	{
// 		old_path = ft_split(g_envp_copy[index_pwd], '=');
// 		free(g_envp_copy[index_pwd]);
// 		g_envp_copy[index_pwd] = ft_pwdjoinfree("PWD=", new_path);
// 	}
// 	if (index_oldpwd != -1 && index_pwd != -1)
// 	{
// 		if (old_path[1])
// 		{
// 			free(g_envp_copy[index_oldpwd]);
// 			g_envp_copy[index_oldpwd] = ft_strjoin("OLDPWD=", old_path[1]);
// 			free_the_pp(old_path);
// 		}
// 	}
// 	else
// 		free_the_pp(old_path);
// 	if (index_pwd == -1)
// 		free(new_path);
// }

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
		res = chdir(cmd->argv[1]);
		set_exit_code(0);
	}
	update_pwd();
	if (res == -1)
	{
		dprintf(STDERR_FILENO, "minicougar: cd: \
		%s: %s\n", strerror(errno), cmd->argv[1]);
		set_exit_code(1);
	}
}
