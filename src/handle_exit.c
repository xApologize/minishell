/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:29:54 by jrossign          #+#    #+#             */
/*   Updated: 2022/07/11 15:29:55 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_exit(char *line, char **opt, char **envp_copy)
{
	if (line != NULL)
		free(line);
	freeopt(opt);
	freeopt(envp_copy);
	exit(0);
}
