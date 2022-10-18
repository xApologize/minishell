/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:29:51 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:29:52 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

void	error_quotation(t_data *data)
{
	data->error_quotes = false;
	double_check(data);
	if (data->error_quotes == true)
		dprintf(STDERR_FILENO, "minicougar: odd number of quotes\n");
}

static void	skip_quote(t_data *data, int *i, int *trigger, char *c)
{
	while (data->line[*i])
	{
		if (data->line[*i] == *c)
		{
			*trigger = 0;
			*c = 0;
			break ;
		}
		*i += 1;
	}
}

void	double_check(t_data *data)
{
	int		i;
	int		trigger;
	char	c;

	i = 0;
	c = 0;
	trigger = 0;
	while (data->line[i])
	{
		if (data->line[i] == '\'' || data->line[i] == '"')
		{
			c = data->line[i];
			trigger = 1;
			i++;
			skip_quote(data, &i, &trigger, &c);
		}
		i++;
	}
	if (trigger == 1)
		data->error_quotes = true;
}

void	single_check(t_data *data)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (data->line[i])
	{
		if (data->line[i] == '\'' && trigger == 0)
		{
			trigger = 1;
			i++;
			while (data->line[i] != '\'' && data->line[i])
				i++;
		}
		if (data->line[i] == '\'' && trigger == 1)
			trigger = 0;
		i++;
	}
	if (trigger == 1)
		data->error_quotes = true;
}
