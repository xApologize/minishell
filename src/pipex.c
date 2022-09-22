#include "../include/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	pipex(t_cmd *cmd, t_data *data)
{
	int	i;
	int	*pid_child;
	int	status;
	int	stdin_copy;
	int	stdout_copy;

	pid_child = malloc(sizeof(int) * table_length(cmd));
	i = 0;
	(void) data;
	stdin_copy = dup(STDIN_FILENO);
	stdout_copy = dup(STDOUT_FILENO);
	while (cmd != NULL)
	{
		pid_child[i] = handle_pipe_cmd(cmd, data);
		i++;
		cmd = cmd->next;
	}
	while (i >= 0)
		waitpid(pid_child[--i], &status, 0);
	dup2(stdin_copy, STDIN_FILENO);
	dup2(stdout_copy, STDOUT_FILENO);
	free(pid_child);
}

int	pipex_redir(t_cmd *cmd, t_data *data)
{
	int	pid;
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
		redir_utils(cmd);
		close(pipe_fd[PIPE_READ]);
		dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
		close(pipe_fd[PIPE_WRITE]);
		if (cmd->is_builtin == 1)
			handle_builtin(cmd, data);
		else
			exec_cmd(cmd);
	}
	close(pipe_fd[PIPE_READ]);
	close(pipe_fd[PIPE_WRITE]);
	close_fork_fd(cmd);
	return (pid);
}

int	exec_fork_cmd(t_cmd	*cmd)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		redir_utils(cmd);
		exec_cmd(cmd);
	}
	close_fork_fd(cmd);
	return (pid);
}

void	exec_cmd(t_cmd *cmd)
{
	execve(cmd->cmd, cmd->argv, cmd->env);
	dprintf(2, "something went wrong: %s\n", cmd->cmd);
	exit(127);
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
