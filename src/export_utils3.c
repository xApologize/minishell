/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:12:35 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 16:12:37 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

char	*strip_quotes(char *arg)
{
	char	**split_arg;
	char	*new_arg;
	char	*line;

	split_arg = ft_split(arg, '=');
	new_arg = NULL;
	if (split_arg[1] && (split_arg[1][0] == '"' || split_arg[1][0] == '\''))
	{
		line = make_arg(split_arg);
		new_arg = ft_strdup(split_arg[0]);
		new_arg = ft_strjoinfree(new_arg, "=");
		new_arg = ft_strjoinfree(new_arg, line);
		free_the_pp(split_arg);
		free(line);
		return (new_arg);
	}
	free_the_pp(split_arg);
	return (ft_strdup(arg));
}

char	*make_arg(char **split_arg)
{
	char	*line;
	int		i;

	line = ft_calloc(1, 1);
	i = 0;
	while (split_arg[++i])
		line = ft_strjoinfree(line, split_arg[i]);
	line = stripstring(line);
	return (line);
}