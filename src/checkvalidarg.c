/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvalidarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:16:13 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:16:15 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

//checks if arg is valid. If not returns 0
bool	checkvalidarg(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (ft_isalnum(arg[i]) == 0 && arg[i] != '_')
			return (false);
	}
	return (true);
}
