/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeopt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:29:19 by jrossign          #+#    #+#             */
/*   Updated: 2022/07/11 15:29:23 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	freeopt(char **opt)
{
	int	i;

	i = 0;
	while (opt[i])
	{
		free(opt[i]);
		i++;
	}
	free(opt);
}
