#include "../include/minishell.h"

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