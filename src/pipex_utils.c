#include "../include/minishell.h"
#include <unistd.h>

void	redir_utils(t_cmd *cmd)
{
	if (cmd->redir_in != STDIN_FILENO)
	{
		dup2(cmd->redir_in, STDIN_FILENO);
		close(cmd->redir_in);
	}
	if (cmd->redir_out != STDOUT_FILENO)
	{
		dup2(cmd->redir_out, STDOUT_FILENO);
		close(cmd->redir_out);
	}
}

void	close_fork_fd(t_cmd *cmd)
{
	if (cmd->redir_in != STDIN_FILENO)
		close(cmd->redir_in);
	if (cmd->redir_out != STDOUT_FILENO)
		close(cmd->redir_out);
}

int	handle_pipe_cmd(t_cmd *cmd, t_data *data)
{

	if (cmd->is_builtin == 1)
		handle_builtin(cmd, data);
	else if (cmd->next != NULL)
		return (pipex_redir(cmd));
	else if (cmd->cmd == NULL)
		return (0);
	else
		return (exec_fork_cmd(cmd));
	return (0);
}
