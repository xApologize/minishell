#include "../include/minishell.h"

void	handle_exit(t_cmd *cmd, t_data *data)
{
	(void) cmd;
	//(void) data;
	free_data(data);
	//free_cmd(cmd);
	exit(0);
}
