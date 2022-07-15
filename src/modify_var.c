#include "../include/minishell.h"

//Function used to replace an already existing variable updated using export to a new value 
char	**modify_var(char *arg, char **envp_copy)
{
	int	index;

	index = find_var(arg, envp_copy);
	free(envp_copy[index]);
	envp_copy[index] = ft_strdup(arg);
	return (envp_copy);
}