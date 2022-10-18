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

	split_arg = ft_split(arg, '=');
	new_arg = NULL;
	if (split_arg[1][0] == '"' || split_arg[1][0] == '\'')
	{
		split_arg[1] = stripstring(split_arg[1]);
		new_arg = ft_strdup(split_arg[0]);
		new_arg = ft_strjoinfree(new_arg, "=");
		new_arg = ft_strjoinfree(new_arg, split_arg[1]);
		free_the_pp(split_arg);
		return (new_arg);
	}
	free_the_pp(split_arg);
	return (ft_strdup(arg));
}
