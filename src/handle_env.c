/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:29:48 by jrossign          #+#    #+#             */
/*   Updated: 2022/07/11 15:29:49 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Implementation of env builtin
void	handle_env(char **opt, char **envp_copy)
{
	int	i;

	i = 0;
	if (opt[1] != NULL)
		dprintf(STDERR_FILENO, "env: %s: No such file or directory\n", opt[1]);
	else
	{
		while (envp_copy[i])
		{
			printf("%s\n", envp_copy[i]);
			i++;
		}
	}
	freeopt(opt);
}
