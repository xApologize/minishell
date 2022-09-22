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
		if (cmd_copy->argv)
			freeopt(cmd_copy->argv);
		free(cmd_copy);
	}
	free(cmd);
}
