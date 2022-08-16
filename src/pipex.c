#include "../include/minishell.h"
#include <sys/wait.h>

void	pipex(t_cmd *cmd)
{
	pipex_redir(cmd);
	exec_cmd(cmd);
}

void	pipex_redir(t_cmd *cmd)
{
	int	pid;
	int	pipe_fd[2];
	int	*status;

	pipe(pipe_fd);
	pid = fork();
	if (pid > 0)
	{
		close(pipe_fd[PIPE_WRITE]);
		dup2(pipe_fd[PIPE_READ], STDIN_FILENO);
		close(pipe_fd[PIPE_READ]);
		waitpid(pid, status, 0);
		set_exit_code(WEXITSTATUS(status));
	}
	if (pid == 0)
	{
		close(pipe_fd[PIPE_READ]);
		dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
		close(pipe_fd[PIPE_WRITE]);
		exec_cmd(cmd);
	}
}

void	exec_cmd(t_cmd *cmd)
{
	execve(cmd->cmd, cmd->argv, cmd->environ);
	dprintf(2, "something went wrong: %s\n", cmd->cmd);
	exit(0);
}
