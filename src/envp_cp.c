#include "../include/minishell.h"
extern char **g_envp_copy;

//makes a copy of the original environment variables
char	**envp_cp(char **envp)
{
	char	**envp_copy;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	envp_copy = ft_calloc((i + 1), sizeof(char *));
	i = 0;
	while (envp[i])
	{
		envp_copy[i] = ft_strdup(envp[i]);
		i++;
	}
	envp[i] = NULL;
	return (envp_copy);
}
