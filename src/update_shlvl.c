/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:32:30 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:32:32 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

static int	find_shlvl(void)
{
	char	**envp_split;
	int		i;

	i = -1;
	while (g_envp_copy[++i])
	{
		envp_split = ft_split(g_envp_copy[i], '=');
		if (ft_strcmp(envp_split[0], "SHLVL") == 0)
		{
			free_the_pp(envp_split);
			return (i);
		}
		free_the_pp(envp_split);
	}
	free_the_pp(envp_split);
	return (-1);
}

static void	change_shlvl(char **shlvl_split, int index)
{
	int		level;
	char	*string_level;

	level = ft_atoi(shlvl_split[1]);
	level++;
	free(g_envp_copy[index]);
	g_envp_copy[index] = ft_strdup("SHLVL=");
	string_level = ft_itoa(level);
	g_envp_copy[index] = ft_strjoinfree(g_envp_copy[index], string_level);
	free(string_level);
}

void	update_shlvl(void)
{
	char	**shlvl_split;
	int		index;

	index = find_shlvl();
	if (index == -1)
		return ;
	else
	{
		shlvl_split = ft_split(g_envp_copy[index], '=');
		if (check_if_num(shlvl_split[1]) == true)
		{
			change_shlvl(shlvl_split, index);
			free_the_pp(shlvl_split);
		}
		else
		{
			free_the_pp(shlvl_split);
			return ;
		}
	}
}
