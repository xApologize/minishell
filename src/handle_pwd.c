#include "../include/minishell.h"

void	handle_pwd(char **opt)
{
	int args;
	char *path;

	path = NULL;
	args = 0;
	while (opt[args])
		args++;
	if (args > 1)
		ft_putstr_fd("pwd: too many arguments\n", STDERR_FILENO);
	path = getcwd(path, 0);
	printf("%s\n", path);
	free(path);
}