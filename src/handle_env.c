#include "../include/minishell.h"

// Implementation of env builtin
void	handle_env(t_cmd *cmd)
{
	int i;

	i = 0;
	if (cmd->argv[1] != NULL)
		dprintf(STDERR_FILENO, "env: %s: No such file or directory\n", cmd->argv[1]);
	else
		while (cmd->env[i])
		{
			printf("%s\n", cmd->env[i]);
			i++;
		}
}
