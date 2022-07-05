#include "../include/minishell.h"
#include <unistd.h>

void	pipex(t_cmd *cmd)
{
	int	pid;
	int	pipe_fd[2];

	pipe(pipe_fd);
	while (cmd != NULL)
	{
		if (cmd->next != NULL)
			redir(pipe_fd, pid);
		else
		{
			pid = fork();
			if (pid == 0)
				exec_cmd(cmd, pipe_fd);
		}
		cmd = cmd->next;
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

void	exec_cmd(t_cmd *cmd, int pipe_fd[2])
{
	execve(cmd->cmd, cmd->argv, cmd->environ);
	dprintf(2, "something went wrong: %s\n", cmd->cmd);
	exit(0);
}

void	redir(int pipe_fd[2], int pid)
{
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
	}
}

// void	exec_cmd(t_cmd *cmd, int pipe_fd[2])
// {
// 	if (cmd->first == 1)
// 		dup2(pipe_fd[1], 1);
// 	else if (cmd->first == 0 && cmd->next != NULL)
// 	{
// 		dup2(pipe_fd[0], 0);
// 		dup2(pipe_fd[1], 1);
// 	}
// 	else 
// 		dup2(pipe_fd[0], 0);
// 	close(pipe_fd[0]);
// 	close(pipe_fd[1]);
// 	execve(cmd->cmd, cmd->argv, cmd->envp);
// 	dprintf(2, "something went wrong: %s\n", cmd->cmd);
// 	exit(0);
// }
