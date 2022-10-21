/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:40:46 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 15:40:51 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

//searches the environment variables for
//the OLDPWD. Returns the index if found, -1 if not
int	find_pwd(void)
{
	int		index;
	char	**envp_split;

	index = -1;
	while (g_envp_copy[++index])
	{
		envp_split = ft_split(g_envp_copy[index], '=');
		if (ft_strcmp("PWD", envp_split[0]) == 0)
		{
			free_the_pp(envp_split);
			return (index);
		}
		free_the_pp(envp_split);
	}
	return (-1);
}
