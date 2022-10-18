/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton_statuscode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:31:47 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:31:48 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern char	**g_envp_copy;

int	*get_exit_code(void)
{
	static int	exit_code;

	return (&exit_code);
}

void	set_exit_code(int status_code)
{
	int	*code;

	code = get_exit_code();
	*code = status_code;
}
