/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:27:22 by jrossign          #+#    #+#             */
/*   Updated: 2022/07/11 15:27:23 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_n(char *opt)
{
	int	i;

	i = 0;
	if (opt[0] != '-')
		return (0);
	else
	{
		while (opt[++i])
			if (opt[i] != 'n')
				return (0);
	}
	return (1);
}
