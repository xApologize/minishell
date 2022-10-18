/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:20:06 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:20:08 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

void	check_validity(t_data *data)
{
	int	i;
	int	trigger;

	i = -1;
	trigger = 0;
	data->parse_status = false;
	while (data->line[++i])
	{
		if (ft_strchr("<>|", data->line[i]) && trigger == 0)
			set_trigger_on(&i, &trigger, data);
		if (!ft_strchr("<>|", data->line[i]) && data->line[i] != ' ' \
			&& ft_isprint(data->line[i]) == 1 && trigger == 1)
			trigger = 0;
		if (ft_strchr("\n|", data->line[i]) && trigger == 1)
		{
			data->parse_status = true;
			break ;
		}
	}
}

void	parsing(t_data *data, t_cmd *cmd)
{
	error_quotation(data);
	data->stdin_cp = dup(STDIN_FILENO);
	data->stdout_cp = dup(STDOUT_FILENO);
	if (data->error_quotes == false)
	{
		check_validity(data);
		if (data->parse_status == false)
		{
			tokenize(data);
			env_split(data);
			data->save_indexmeta = data->indexmeta;
			data->save_line = data->line;
			cmd = set_exec_struct(data);
			search_cmd(data, cmd);
		}	
		else
			print_parse_error(data);
	}
	close(data->stdin_cp);
	close(data->stdout_cp);
}

void	tokenize(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->line_lenght = ft_strlen(data->line);
	findlenght(data);
	i = 0;
	while (data->line[i] != '\0')
	{
		if (ft_strchr(QUOTES, data->line[i]))
			i = quote(i, data);
		if (ft_strchr(WS_METACHAR, data->line[i]))
		{
			data->indexmeta[j] = data->line[i];
			data->line[i] = '\0';
			j++;
		}
		i++;
	}
}

int	quote(int i, t_data *data)
{
	if (ft_strchr("\'", data->line[i]))
	{
		i++;
		while (!ft_strchr("\'", data->line[i]))
			i++;
	}
	if (ft_strchr("\"", data->line[i]))
	{
		i++;
		while (!ft_strchr("\"", data->line[i]))
			i++;
	}
	return (i);
}

void	findlenght(t_data *data)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = 0;
	while (data->line[i] != '\0')
	{
		if (ft_strchr(QUOTES, data->line[i]) && data->line[i])
			i = quote(i, data);
		if (ft_strchr(WS_METACHAR, data->line[i]) && data->line[i])
			lenght++;
		i++;
	}
	data->indexmeta = ft_calloc(lenght + 1, sizeof (char));
}
