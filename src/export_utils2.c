/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:17:51 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:17:53 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

//adds the new variable to the environment
void	addtoenv(char *arg)
{
	char	**new_envp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (g_envp_copy[i])
		i++;
	new_envp = malloc((i + 2) * sizeof(char *));
	while (g_envp_copy[++j])
		new_envp[j] = ft_strdup(g_envp_copy[j]);
	new_envp[i] = ft_strdup(arg);
	new_envp[i + 1] = NULL;
	free_the_pp(g_envp_copy);
	g_envp_copy = new_envp;
}

//if the argument was already part of the
//environement variables, modifies it to the new value
void	modify_var(char *arg)
{
	int		index;
	char	**split_arg;
	char	*new_arg;
	char	*line;

	index = find_var(arg);
	split_arg = ft_split(arg, '=');
	if (split_arg[1])
	{
		line = make_arg(split_arg);
		new_arg = ft_strdup(split_arg[0]);
		new_arg = ft_strjoinfree(new_arg, "=");
		new_arg = ft_strjoinfree(new_arg, line);
		free(g_envp_copy[index]);
		free(line);
		g_envp_copy[index] = ft_strdup(new_arg);
		free(new_arg);
	}
	else
	{
		free(g_envp_copy[index]);
		g_envp_copy[index] = ft_strdup(arg);
	}
	free_the_pp(split_arg);
}

//checks if the argument is already in the environment variables
char	*return_stripped_env(char **split_arg)
{
	char	*new_arg;

	new_arg = NULL;
	split_arg[1] = stripstring(split_arg[1]);
	new_arg = ft_strdup(split_arg[0]);
	new_arg = ft_strjoinfree(new_arg, "=");
	new_arg = ft_strjoinfree(new_arg, split_arg[1]);
	return (new_arg);
}

int	check_dup_env(char *arg)
{
	int		i;
	char	*new_arg;

	i = -1;
	new_arg = ft_strdup(arg);
	while (g_envp_copy[++i])
	{
		if (ft_strcmp(g_envp_copy[i], new_arg) == 0)
		{
			free(new_arg);
			return (1);
		}
	}
	free(new_arg);
	return (0);
}

bool	checkassign(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if ((ft_isalnum(arg[i]) == 1 || arg[i] == '"' \
			|| arg[i] == '\'') && arg[i + 1] == '=')
			return (true);
	}
	return (false);
}
