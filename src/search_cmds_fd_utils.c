/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_cmds_fd_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:30:24 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/19 16:35:12 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"
#include <unistd.h>

extern char	**g_envp_copy;

void	set_fd_in(t_cmd *cmd, t_data *data)
{
	char	*placeholder;

	if (!cmd || !data)
		return ;
	while (*data->line == '\0' && ft_strchr(" <", *data->indexmeta))
		skip_char(data);
	if (*data->line == '\0' && *data->indexmeta == ' ')
		return ;
	placeholder = stripstring(ft_strdup(data->line));
	if (access(placeholder, F_OK) == 0)
	{
		if (cmd->redir_in != STDIN_FILENO)
			close(cmd->redir_in);
		cmd->redir_in = open(placeholder, O_RDWR);
	}
	else
	{
		cmd->redir_in = -1;
		dprintf(2, "minicougar: %s: No such file or directory\n", data->line);
	}
	free(placeholder);
	while (*data->line != '\0')
		data->line++;
}

void	set_fd_out(t_cmd *cmd, int append, t_data *data)
{
	char	*placeholder;

	if (!cmd || !data->line)
		return ;
	while (*data->line == '\0' && ft_strchr(" >", *data->indexmeta))
		skip_char(data);
	placeholder = stripstring(ft_strdup(data->line));
	if (append == 0)
	{
		if (cmd->redir_out != STDOUT_FILENO)
			close(cmd->redir_out);
		cmd->redir_out = open(placeholder,
				O_RDWR | O_TRUNC | O_CREAT, 0777);
	}
	else
	{
		if (cmd->redir_out != STDOUT_FILENO)
			close(cmd->redir_out);
		cmd->redir_out = open(placeholder,
				O_RDWR | O_APPEND | O_CREAT, 0777);
	}
	free(placeholder);
	while (*data->line != '\0')
		data->line++;
}

void	get_fd(t_cmd *cmd, t_data *data, char meta)
{
	if (meta == '<')
	{
		if (data->line[1] == '\0' && data->indexmeta[1] == '<')
			cmd->redir_in = heredoc(data);
		else
			set_fd_in(cmd, data);
	}
	else if (meta == '>')
	{
		if (data->line[1] == '\0' && data->indexmeta[1] == '>')
			set_fd_out(cmd, 1, data);
		else
			set_fd_out(cmd, 0, data);
	}
}

void	close_fd(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		if (tmp->redir_in != STDIN_FILENO)
			close(tmp->redir_in);
		if (tmp->redir_out != STDOUT_FILENO)
			close(tmp->redir_out);
		tmp = tmp->next;
	}
}
