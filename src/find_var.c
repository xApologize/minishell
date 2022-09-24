#include "../include/minishell.h"

//Function to find the index of an existing variable so it can be replaced with an updated value
int	find_var(char *arg)
{
	int		index;
	char	**arg_split;
	char	**envp_split;

	index = -1;
	arg_split = ft_split(arg, '=');
	while (g_envp_copy[++index])
	{
		envp_split = ft_split(g_envp_copy[index], '=');
		if (ft_strcmp(arg_split[0], envp_split[0]) == 0)
		{
			free_the_pp(arg_split);
			free_the_pp(envp_split);
			return (index);
		}
		free_the_pp(envp_split);
	}
	free_the_pp(arg_split);
	return (-1);
}