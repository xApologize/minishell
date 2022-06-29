#include "../include/minishell.h"

//cd builtin implementation using chdir

void	handle_cd(char **opt)
{
	int args;

	args = 0;
	while (opt[args])
		args++;
	if (args > 2)
		ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
	if (args == 1)
		dprintf(STDERR_FILENO, "cd: not enough arguments\n");
	if (chdir(opt[1]) == -1 && args == 2)
		dprintf(STDERR_FILENO, "cd: %s: %s\n", strerror(errno), opt[1]);
}