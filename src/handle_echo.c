/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:29:43 by jrossign          #+#    #+#             */
/*   Updated: 2022/07/11 15:29:44 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_echo(char *line, char **opt)
{
	if (check_n(opt[1]) == 1)
		print_echo_with_n(line);
	else
		print_echo_without_n(line);
}
