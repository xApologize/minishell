#include "../include/minishell.h"

void	pipex(t_cmd *cmd)
{
	int	pid;

	while (cmd != NULL)
	{
		pid = fork();
		if (pid == 0)
			exec_cmd(cmd);
		cmd = cmd->next;
	}
}

void	exec_cmd(t_cmd *cmd)
{
	printf("cmd-> cmd: %s\n", cmd->cmd);
	exit(0);
}
