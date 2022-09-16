#include "../include/minishell.h"


void	handle_pwd(t_cmd *cmd)
{
	int args;
	char *path;

	path = NULL;
	args = 0;
	while (cmd->argv[args])
		args++;
	if (args > 1)
		ft_putstr_fd("pwd: too many arguments\n", STDERR_FILENO);
	else
	{
		path = getcwd(path, 0);
		printf("%s\n", path);
		free(path);
	}
}
