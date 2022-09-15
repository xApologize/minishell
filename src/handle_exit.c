#include "../include/minishell.h"

void	handle_exit(t_cmd *cmd, char **envp_copy)
{
	freeopt(opt);
	freeopt(envp_copy);
	exit(0);
}