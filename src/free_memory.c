/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:18:01 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:18:02 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*cmd_copy;

	if (!cmd)
		return ;
	while (cmd != NULL)
	{
		cmd_copy = cmd;
		cmd = cmd->next;
		if (cmd_copy->argv)
			free_the_pp(cmd_copy->argv);
		if (cmd_copy->cmd)
			free(cmd_copy->cmd);
		free(cmd_copy);
	}
	free(cmd);
}

//free char **
void	free_the_pp(char **pp)
{
	int	i;

	i = 0;
	if (!pp || !*pp)
		return ;
	while (pp[i])
	{
		free(pp[i]);
		pp[i] = NULL;
		i++;
	}
	free(pp);
	pp = NULL;
}

void	free_data(t_data *data)
{
	data->indexmeta = data->save_indexmeta;
	free(data->indexmeta);
	data->line = data->save_line;
	free(data->line);
	free_the_pp(data->path_split);
}

void	free_data_cmd(t_cmd *cmd, t_data *data)
{
	free_cmd(cmd);
	free_data(data);
}

void	free_all(t_cmd *cmd, t_data *data)
{
	free_cmd(cmd);
	free_data(data);
	free_the_pp(g_envp_copy);
}
