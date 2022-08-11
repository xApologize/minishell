#include "../include/minishell.h"

void	pipex(t_cmd *cmd)
{
	while (cmd->next != NULL)
	{
		pipex_redir(cmd);
		cmd = cmd->next;
	}
	pipex_redir(cmd);
	exec_cmd(cmd);
}

void	pipex_redir(t_cmd *cmd, int file_descriptor)
{
	int	pid;
	int	pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid > 0)
	{
		close(pipe_fd[PIPE_WRITE]);
		dup2(pipe_fd[cmd->file_read], STDIN_FILENO);
		close(pipe_fd[cmd->file_read]);
	}
	if (pid == 0)
	{
		close(pipe_fd[cmd->file_read]);
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
