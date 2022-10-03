#include "../include/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	pipex(t_cmd *cmd, t_data *data)
{
	int	i;
	int	*pid_child;
	int	table_size;

	table_size = table_length(cmd);
	pid_child = malloc(sizeof(int) * table_size);
	i = 0;
	while (cmd != NULL)
	{
		pid_child[i] = handle_pipe_cmd(cmd, data);
		i++;
		cmd = cmd->next;
	}
	wait_child(pid_child, table_size);
	restore_std(data);
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
		{
			handle_builtin(cmd, data);
			exit(1);
		}
		exec_cmd(cmd, data);
	}
	close(pipe_fd[PIPE_READ]);
	close(pipe_fd[PIPE_WRITE]);
	close_fork_fd(cmd);
	return (pid);
}

int	exec_fork_cmd(t_cmd	*cmd, t_data *data)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		redir_utils(cmd);
		if (cmd->is_builtin == 1)
		{
			handle_builtin(cmd, data);
			exit(1);
		}
		exec_cmd(cmd, data);
	}
	restore_std(data);
	close_fork_fd(cmd);
	return (pid);
}

void	exec_cmd(t_cmd *cmd, t_data *data)
{
	close(data->stdin_cp);
	close(data->stdout_cp);
	execve(cmd->cmd, cmd->argv, g_envp_copy);
	dprintf(2, "minicougarsh: %s: command not found\n", cmd->cmd);
	free_data_cmd(cmd, data);
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
