/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:29:57 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:29:58 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

//uses readline to get input from stdin. Adds the line to history
char	*rl_gets(void)
{
	char	*line;
	char	*backslash;

	printf("\033[0;37m");
	line = readline("minicougar>$ ");
	if (line && *line)
		add_history(line);
	backslash = ft_strjoinfree(line, "\n");
	return (backslash);
}
