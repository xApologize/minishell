#include "../include/minishell.h"

void	handle_unset(char **opt, char **envp_copy)
{
	int args;

	args = 0;
	while (opt[args])
		args++;
	if (args > 1)
		ft_putstr_fd("unset: too many arguments\n", STDERR_FILENO);
	else
	{
		args = 0;
		while (envp_copy[args])
		{
			free(envp_copy[args]);
			envp_copy[args] = NULL;
			args++;
		}
		free(envp_copy[args]);
		envp_copy = NULL;
	}
}