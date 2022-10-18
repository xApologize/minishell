/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:29:42 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:29:44 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern char	**g_envp_copy;

void	quit_handling(int signum)
{
	struct termios	termios_save;

	tcgetattr(0, &termios_save);
	termios_save.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &termios_save);
	if (signum == 3)
	{
		write(1, "Quit\n", 5);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}
