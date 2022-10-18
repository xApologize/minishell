/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:19:55 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:19:56 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern char	**g_envp_copy;

int	get_mem_len(char *arg, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (arg[++i])
	{
		if (arg[i] != c)
			count++;
	}
	return (count);
}

char	*stripstring(char *arg)
{
	char	*new_string;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (arg[0] == '\'' || arg[0] == '"')
	{
		new_string = ft_calloc((get_mem_len(arg, arg[0]) + 1), sizeof (char));
		while (arg[++i])
		{
			if (arg[i] != arg[0])
			{
				new_string[j] = arg[i];
				j++;
			}
		}
		new_string[j] = '\0';
		free(arg);
		return (new_string);
	}
	return (arg);
}

char	*skip_single_quote(char *line)
{
	if (*(line - 1) == '"')
		return (line + 1);
	line++;
	while (*line != '\'' && *line)
		line++;
	return (line);
}

bool	check_if_num(const char *n)
{
	int	i;

	i = -1;
	while (n[++i])
	{
		if (ft_isdigit(n[i]) == 0)
			return (false);
	}
	return (true);
}
