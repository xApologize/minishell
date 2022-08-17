#include "../include/minishell.h"
#include <sys/wait.h>

void	pipex(t_cmd *cmd)
{

	int	pid;

	pid = fork();
	if (pid == 0)
	{
		while (cmd->next != NULL)
		{
			pipex_redir(cmd);
			cmd = cmd->next;
		}
		exec_cmd(cmd);
	}
	waitpid(pid, NULL, 0);
}

void	pipex_redir(t_cmd *cmd)
{
	int	pid;
	int	status;
	int	pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid > 0)
	{
		close(pipe_fd[PIPE_WRITE]);
		dup2(pipe_fd[PIPE_READ], STDIN_FILENO);
		close(pipe_fd[PIPE_READ]);
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
