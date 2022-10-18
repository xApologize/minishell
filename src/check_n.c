/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:15:45 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:15:52 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

//checks if argument contains -n option. Works with multiple chained n's
int	check_n(char *opt)
{
	int	i;

	i = 0;
	if (opt[0] != '-')
		return (0);
	else
	{
		while (opt[++i])
			if (opt[i] != 'n')
				return (0);
	}
	return (1);
}
