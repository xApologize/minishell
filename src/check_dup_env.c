#include "../include/minishell.h"

int	check_dup_env(char *arg, char **envp_copy)
{
	int	i;

	i = -1;
	while (envp_copy[++i])
	{
		if (ft_strcmp(envp_copy[i], arg) == 0)
			return (1);
	}
	return (0);
}