#include "../include/minishell.h"
#include <unistd.h>

void	restore_std(t_data *data)
{
	dup2(data->stdin_cp, STDIN_FILENO);
	dup2(data->stdout_cp, STDOUT_FILENO);
	close(data->stdin_cp);
	close(data->stdout_cp);
}
