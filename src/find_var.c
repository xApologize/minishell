#include "../include/minishell.h"

//Function to find the index of an existing variable so it can be replaced with an updated value
int	find_var(char *arg, char **envp_copy)
{
	int		index;
	char	**arg_split;
	char	**envp_split;

	index = -1;
	arg_split = ft_split(arg, '=');
	while (envp_copy[++index])
	{
		envp_split = ft_split(envp_copy[index], '=');
		if (ft_strcmp(arg_split[0], envp_split[0]) == 0)
		{
			freeopt(arg_split);
			freeopt(envp_split);
			return (index);
		}
		freeopt(envp_split);
	}
	freeopt(arg_split);
	return (-1);
}