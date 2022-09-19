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
