/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkenvformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:16:00 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:16:05 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

int	checkenvformat(char *var)
{
	int	i;

	i = -1;
	while (var[++i])
	{
		if (var[i] == '=' && \
		ft_isprint(var[i - 1]) == 1 && ft_isprint(var[i + 1]) == 1)
			return (1);
	}
	return (0);
}
