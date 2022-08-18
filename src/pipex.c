#include "../include/minishell.h"
#include <stdio.h>
#include <sys/wait.h>

void	pipex(t_cmd *cmd)
{

	int	pid;
	int	cmd_count;
	int	i;
	int *pid_child;

	cmd_count = table_length(cmd);
	pid_child = malloc(sizeof(int) * cmd_count);
	i = 0;
	pid = fork();
	if (pid == 0)
	{
		while (cmd != NULL)
		{
			i = pipex_redir(cmd);
			printf("i: %d\n", i);
			cmd = cmd->next;
		}
	}
	waitpid(pid, NULL, 0);
}

int	pipex_redir(t_cmd *cmd)
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
	return (pid);
}

void	exec_cmd(t_cmd *cmd)
{
	execve(cmd->cmd, cmd->argv, cmd->environ);
	dprintf(2, "something went wrong: %s\n", cmd->cmd);
	exit(0);
}

int	table_length(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	tmp = cmd;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
