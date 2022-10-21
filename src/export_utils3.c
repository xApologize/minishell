/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:12:35 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/21 11:11:28 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

char	*make_arg(char **split_arg)
{
	char	*line;
	int		i;

	line = ft_calloc(1, 1);
	i = 0;
	while (split_arg[++i])
		line = ft_strjoinfree(line, split_arg[i]);
	return (line);
}
