#include "../include/minishell.h"

char	**addtoenv(char *arg, char **envp_copy)
{
	char	**new_envp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (envp_copy[i])
		i++;
	new_envp = malloc((i + 2) * sizeof(char *));
	while (envp_copy[++j])
		new_envp[j] = ft_strdup(envp_copy[j]);
	new_envp[i] = ft_strdup(arg);
	new_envp[i + 1] = NULL;
	freeopt(envp_copy);
	return (new_envp);
}