/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_cp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:28:56 by jrossign          #+#    #+#             */
/*   Updated: 2022/07/11 15:28:57 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**envp_cp(char **envp)
{
	char	**envp_copy;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	envp_copy = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (envp[i])
	{
		envp_copy[i] = ft_strdup(envp[i]);
		i++;
	}
	envp[i] = NULL;
	return (envp_copy);
}
