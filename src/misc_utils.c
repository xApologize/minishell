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

char	*stripstring(char *arg)
{
	char	*new_string;
	int		i;
	char	c;

	i = -1;
	new_string = ft_calloc(1, 1);
	while (arg[++i])
	{
		while (arg[i] == '\'' || arg[i] == '"')
		{
			c = arg[i];
			while (arg[++i] != c)
				new_string = charjoinfree(new_string, arg[i]);
			i++;
		}
		if (!arg[i])
			break ;
		new_string = charjoinfree(new_string, arg[i]);
	}
	free(arg);
	return (new_string);
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
