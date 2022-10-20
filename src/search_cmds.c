/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:30:05 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/20 10:27:01 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

static void	free_both(char *line, char **builtin)
{
	free(line);
	free(builtin);
}

char	**create_table(void)
{
	char	**builtin;

	builtin = ft_calloc(10, sizeof (char *));
	builtin[0] = "echo";
	builtin[1] = "cd";
	builtin[2] = "pwd";
	builtin[3] = "export";
	builtin[4] = "unset";
	builtin[5] = "env";
	builtin[6] = "exit";
	builtin[7] = "pepe";
	builtin[8] = "owo";
	builtin[9] = NULL;
	return (builtin);
}

int	is_builtin(char *line)
{
	int		i;
	char	**builtin;

	i = -1;
	builtin = create_table();
	line = handle_string(line);
	while (builtin[++i])
	{
		if (ft_strcmp(line, builtin[i]) == 0)
		{
			free_both(line, builtin);
			return (1);
		}
	}
	free_both(line, builtin);
	return (0);
}

void	set_cmd(t_cmd *cmd, t_data *data)
{
	char	*line_cp;

	line_cp = data->line;
	if (is_builtin(ft_strdup(line_cp)) == 1)
	{
		cmd->is_builtin = 1;
		cmd->cmd = ft_strdup(line_cp);
	}
	else
		cmd->cmd = get_path(ft_strdup(data->line), data);
	while (*line_cp != '\0')
		line_cp++;
	cmd->argv = get_argv(data);
	while (*data->line != '\0')
		data->line++;
}

void	search_cmd(t_data *data, t_cmd *cmd)
{
	t_cmd	*tmp_cmd;

	tmp_cmd = cmd;
	quiet_handling();
	while (*data->indexmeta != '\0')
	{
		if (*data->line == '\0' && ft_strchr("<>", *data->indexmeta))
			get_fd(tmp_cmd, data, *data->indexmeta);
		else if (*data->line == '\0' && ft_strchr(" \n", *data->indexmeta))
			skip_char(data);
		else if (*data->line == '\0' && *data->indexmeta == '|')
		{
			tmp_cmd = tmp_cmd->next;
			skip_char(data);
		}
		else
			set_cmd(tmp_cmd, data);
	}
	if (cmd->is_builtin == 1 && cmd->next == NULL)
		handle_single_builtin(cmd, data);
	else
		pipex(cmd, data);
	close_fd(cmd);
	free_data_cmd(cmd, data);
}
