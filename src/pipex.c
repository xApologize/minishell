#include "../include/minishell.h"
#include <stdio.h>

void	pipex(t_cmd *cmd, t_data *data)
{
	int	pid;
	int	i;
	int	*pid_child;
	int	status;

	pid_child = malloc(sizeof(int) * table_length(cmd));
	i = 0;
	while (cmd != NULL)
	{
		if (cmd->is_builtin == 1)
			cmd->env = handle_builtin(cmd, data);
		if (cmd->next != NULL)
			pid_child[i] = pipex_redir(cmd);
		else
			pid_child[i] = exec_fork_cmd(cmd);
		i++;
		cmd = cmd->next;
	}
	while (i >= 0)
		waitpid(pid_child[--i], &status, 0);
}

int	pipex_redir(t_cmd *cmd)
{
	int	pid;
	int	pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid > 0)
	{
		close(pipe_fd[cmd->redir_out]);
		dup2(pipe_fd[cmd->redir_in], STDIN_FILENO);
		close(pipe_fd[cmd->redir_out]);
	}
	if (pid == 0)
	{
		close(pipe_fd[cmd->redir_in]);
		dup2(pipe_fd[cmd->redir_out], STDOUT_FILENO);
		close(pipe_fd[cmd->redir_in]);
		exec_cmd(cmd);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (pid);
}

int	exec_fork_cmd(t_cmd	*cmd)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		exec_cmd(cmd);
	return (pid);
}

void	exec_cmd(t_cmd *cmd)
{
	execve(cmd->cmd, cmd->argv, cmd->env);
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
