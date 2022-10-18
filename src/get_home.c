/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_home.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:18:21 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:18:23 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern char	**g_envp_copy;

//gets the value of home from the environment variables
char	*get_home(void)
{
	char	**split_envp;
	char	*rstring;
	int		i;

	i = 0;
	while (g_envp_copy[i])
	{
		split_envp = ft_split(g_envp_copy[i], '=');
		if (ft_strcmp(split_envp[0], "HOME") == 0)
		{
			rstring = ft_strdup(split_envp[1]);
			free_the_pp(split_envp);
			return (rstring);
		}
		free_the_pp(split_envp);
		i++;
	}
	return (NULL);
}
