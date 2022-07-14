#include "../include/minishell.h"

int	check_modify_env(char *arg, char **envp_copy)
{
	int		i;
	char	**split_arg;
	char	**split_envp_copy;

	i = -1;
	split_arg = ft_split(arg, '=');
	while (envp_copy[++i])
	{
		split_envp_copy = ft_split(envp_copy[i], '=');
		if (ft_strcmp(split_arg[0], split_envp_copy[0]) == 0)
		{
			freeopt(split_arg);
			freeopt(split_envp_copy);
			return (1);
		}
		freeopt(split_envp_copy);
	}
	freeopt(split_arg);
	return (0);
}