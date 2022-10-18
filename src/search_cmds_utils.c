/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_cmds_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:30:15 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:30:17 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern char	**g_envp_copy;

void	handle_single_builtin(t_cmd *cmd, t_data *data)
{
	redir_utils(cmd);
	handle_builtin(cmd, data);
	restore_std(data);
}

void	skip_char(t_data *data)
{
	data->indexmeta++;
	data->line++;
}

char	*access_path(char *line)
{
	if (access(line, X_OK) == 0)
		return (ft_strdup(line));
	return (NULL);
}
