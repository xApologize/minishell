/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:18:43 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:18:45 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern char	**g_envp_copy;

// Prints all the environment variables
void	handle_env(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->argv[1] != NULL)
		dprintf(STDERR_FILENO, \
		"env: %s: No such file or directory\n", cmd->argv[1]);
	else
	{
		while (cmd->env[i])
		{
			printf("%s\n", cmd->env[i]);
			i++;
		}
	}
}
