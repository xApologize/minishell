/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:20:28 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/20 15:49:18 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

void	pipex(t_cmd *cmd, t_data *data)
{
	int	i;
	int	pid_child[1000];
	int	table_size;

	table_size = table_length(cmd);
	i = 0;
	while (cmd != NULL)
	{
		pid_child[i] = handle_pipe_cmd(cmd, data);
		i++;
		cmd = cmd->next;
	}
	wait_child(pid_child, table_size);
	restore_std(data);
}

int	pipex_redir(t_cmd *cmd, t_data *data)
{
	int	pid;
	int	pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid > 0)
		redir_pipe(pipe_fd, 0);
	if (pid == 0)
	{
		redir_pipe(pipe_fd, 1);
		redir_utils(cmd);
		if (cmd->is_builtin == 1)
		{
			handle_builtin(cmd, data);
			exit(0);
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
		sig_reset();
		redir_utils(cmd);
		if (cmd->is_builtin == 1)
		{
			handle_builtin(cmd, data);
			exit(0);
		}
		exec_cmd(cmd, data);
	}
	restore_std(data);
	close_fork_fd(cmd);
	return (pid);
}

void	exec_cmd(t_cmd *cmd, t_data *data)
{
	execve(cmd->cmd, cmd->argv, cmd->env);
	if (ft_strlen(cmd->cmd) != 0)
		dprintf(2, "minicougar: %s: command not found\n", cmd->cmd);
	close(data->stdin_cp);
	close(data->stdout_cp);
	free_data_cmd(cmd, data);
	free_the_pp(g_envp_copy);
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
