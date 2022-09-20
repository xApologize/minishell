#include "../include/minishell.h"
#include <stdlib.h>

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*cmd_copy;

	if (!cmd)
		return ;
	while (cmd != NULL)
	{
		cmd_copy = cmd;
		cmd = cmd->next;
		if (cmd_copy->cmd)
			free(cmd_copy->cmd);
		if (cmd_copy->argv)
			freeopt(cmd_copy->argv);
		if (cmd_copy->env)
			freeopt(cmd_copy->env);
		free(cmd_copy);
	}
}
