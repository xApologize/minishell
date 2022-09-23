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
			free_the_pp(cmd_copy->argv);
		if (cmd_copy->cmd)
			free(cmd_copy->cmd);
		free(cmd_copy);
	}
	free(cmd);
}

void free_data(t_data *data)
{
	data->indexmeta = data->save_indexmeta;
	free(data->indexmeta);
	data->line = data->save_line;
	free(data->line);
	free_the_pp(data->path_split);
}

void	free_data_cmd(t_cmd *cmd, t_data *data)
{
	free_cmd(cmd);
	free_data(data);
}
