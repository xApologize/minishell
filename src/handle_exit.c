#include "../include/minishell.h"

void	handle_exit(t_cmd *cmd, t_data *data)
{
	free_data(data);
	free_cmd(cmd);
	free_opt(_envp_copy);
	exit(0);
}
