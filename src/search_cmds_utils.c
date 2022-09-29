#include "../include/minishell.h"

void	handle_single_builtin(t_cmd *cmd, t_data *data)
{
	redir_utils(cmd);
	handle_builtin(cmd, data);
	restore_std(data);
}

void	skip_char(t_data *data)
{
	data->indexmeta++;
	data->line++;
}
