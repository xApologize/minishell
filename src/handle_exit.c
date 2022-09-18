#include "../include/minishell.h"

void	handle_exit(t_cmd *cmd)
{
	(void) cmd;
	//free_data(data);
	exit(0);
}