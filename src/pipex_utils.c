#include "../include/minishell.h"
#include <signal.h>
#include <stdio.h>
#include <sys/signal.h>
#include <sys/wait.h>
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
	if (cmd->next != NULL)
		return (pipex_redir(cmd, data));
	else if (cmd->cmd == NULL)
		return (0);
	else
		return (exec_fork_cmd(cmd, data));
	return (0);
}

void	wait_child(int *pid_child, int table_size)
{
	int	status;
	int	ret;
	int	i;

	i = 0;
	//(void) pid_child;
	while (1)
	{
		if ((ret = waitpid(pid_child[table_size - 1], &status, 0)) == 0)
		{
			set_exit_code(WEXITSTATUS(status));
			break ;
		}
		waitpid(pid_child[i], &status, 0);
		set_exit_code(WEXITSTATUS(status));
		i++;
	}
}
