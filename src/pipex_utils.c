#include "../include/minishell.h"

extern char	**g_envp_copy;

int	handle_pipe_cmd(t_cmd *cmd, t_data *data)
{
	if (cmd->redir_in == -1)
		return(0);
	else if (cmd->next != NULL)
		return (pipex_redir(cmd, data));
	else if (cmd->cmd == NULL)
		return (0);
	else
		return (exec_fork_cmd(cmd, data));
	return (0);
}

void	redir_utils(t_cmd *cmd)
{
	if (cmd->redir_in != STDIN_FILENO)
	{
		if (cmd->redir_in == -1)
			return ;
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

void	redir_pipe(int pipe_fd[2], int std)
{
	if (std == 0)
	{
		close(pipe_fd[PIPE_WRITE]);
		dup2(pipe_fd[PIPE_READ], STDIN_FILENO);
		close(pipe_fd[PIPE_READ]);
	}
	else
	{
		close(pipe_fd[PIPE_READ]);
		dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
		close(pipe_fd[PIPE_WRITE]);
	}
}

void	wait_child(int *pid_child, int table_size)
{
	int	status;
	int	i;

	i = 0;
	sig_ignore();
	while (i < table_size)
	{
		waitpid(pid_child[i], &status, 0);
		if (WIFEXITED(status) == true)
			set_exit_code(WEXITSTATUS(status));
		else if (WIFSIGNALED(status) == true)
			set_exit_code(128 + WTERMSIG(status));
		else
			set_exit_code(128 + WSTOPSIG(status));
		i++;
	}
}

