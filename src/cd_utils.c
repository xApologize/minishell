#include "../include/minishell.h"

static char *ft_pwdjoinfree(const char *s1, const char *s2)
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

int	find_oldpwd(char **envp_copy)
{
	int		index;
	char	**envp_split;

	index = -1;
	while (envp_copy[++index])
	{
		envp_split = ft_split(envp_copy[index], '=');
		if (ft_strcmp("OLDPWD", envp_split[0]) == 0)
		{
			freeopt(envp_split);
			return (index);
		}
		freeopt(envp_split);
	}
	return (-1);
}

int	find_pwd(char **envp_copy)
{
	int		index;
	char	**envp_split;

	index = -1;
	while (envp_copy[++index])
	{
		envp_split = ft_split(envp_copy[index], '=');
		if (ft_strcmp("PWD", envp_split[0]) == 0)
		{
			freeopt(envp_split);
			return (index);
		}
		freeopt(envp_split);
	}
	return (-1);
}


void	update_pwd(char **envp_copy)
{
	int		index_pwd;
	int		index_oldpwd;
	char	*new_path;
	char	**old_path;

	new_path = NULL;
	new_path = getcwd(new_path, 0);
	index_pwd = find_pwd(envp_copy);
	index_oldpwd = find_oldpwd(envp_copy);
	old_path = ft_split(envp_copy[index_pwd], '=');
	free(envp_copy[index_oldpwd]);
	free(envp_copy[index_pwd]);
	envp_copy[index_oldpwd] = ft_strjoin("OLDPWD=", old_path[1]);
	envp_copy[index_pwd] = ft_pwdjoinfree("PWD=", new_path);
	freeopt(old_path);
}

void	handle_cd(char **opt, char **envp_copy)
{
	int args;
	int	res;

	args = 0;
	while (opt[args])
		args++;
	if (args > 2)
		ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
	if (args == 1)
		dprintf(STDERR_FILENO, "cd: not enough arguments\n");
	res = chdir(opt[1]);
	update_pwd(envp_copy);
	if (res == -1 && args == 2)
		dprintf(STDERR_FILENO, "cd: %s: %s\n", strerror(errno), opt[1]);
}
