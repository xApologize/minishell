#include "../include/minishell.h"

void	handle_exit(char **opt)
{
	int args;

	args = 0;
	while (opt[args])
		args++;
	if (args > 1)
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
	else
		exit(0);
}