/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:20:16 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:20:17 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern char	**g_envp_copy;

void	env_split(t_data *data)
{
	int		find;
	char	*tmp;

	find = 0;
	data->path_split = NULL;
	while (g_envp_copy[find])
	{
		if (ft_strncmp(g_envp_copy[find], "PATH=", 5) == 0)
			break ;
		find++;
	}
	if (g_envp_copy[find] == NULL)
		return ;
	data->path_split = ft_split(g_envp_copy[find], ':');
	tmp = ft_strdup(data->path_split[0]);
	free(data->path_split[0]);
	data->path_split[0] = ft_substr(tmp, 5, ft_strlen(tmp) - 5);
	free(tmp);
}

void	set_trigger_on(int *i, int *trigger, t_data *data)
{
	*trigger = 1;
	if ((data->line[*i] == '<' && data->line[*i + 1] == '<') \
		|| (data->line[*i] == '>' && data->line[*i + 1] == '>'))
		*i += 1;
	*i += 1;
}

void	print_parse_error(t_data *data)
{
	free(data->line);
	set_exit_code(127);
	dprintf(STDERR_FILENO, "minicougar: syntax error near unexpected token\n");
}
