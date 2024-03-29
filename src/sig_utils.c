/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:31:24 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:31:26 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

//rewires sigint and sigquit
void	sig_handling(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = sigint_handler;
	sa_sigquit.sa_handler = SIG_IGN;
	sigemptyset(&sa_sigint.sa_mask);
	sigemptyset(&sa_sigquit.sa_mask);
	sa_sigint.sa_flags = SA_RESTART;
	sa_sigquit.sa_flags = 0;
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

void	quiet_handling(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = shush_handler;
	sa_sigquit.sa_handler = quit_handler;
	sigemptyset(&sa_sigint.sa_mask);
	sigemptyset(&sa_sigquit.sa_mask);
	sa_sigint.sa_flags = SA_RESTART;
	sa_sigquit.sa_flags = 0;
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

//reset sigint and sigquit to their original state
void	sig_ignore(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = SIG_IGN;
	sa_sigquit.sa_handler = SIG_IGN;
	sigemptyset(&sa_sigint.sa_mask);
	sigemptyset(&sa_sigquit.sa_mask);
	sa_sigint.sa_flags = 0;
	sa_sigquit.sa_flags = 0;
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

void	sig_reset(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = NULL;
	sa_sigquit.sa_handler = NULL;
	sigemptyset(&sa_sigint.sa_mask);
	sigemptyset(&sa_sigquit.sa_mask);
	sa_sigint.sa_flags = SA_RESETHAND;
	sa_sigquit.sa_flags = SA_RESETHAND;
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

void	sig_heredoc(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = hd_handler;
	sa_sigquit.sa_handler = SIG_IGN;
	sigemptyset(&sa_sigint.sa_mask);
	sigemptyset(&sa_sigquit.sa_mask);
	sa_sigint.sa_flags = 0;
	sa_sigquit.sa_flags = 0;
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}
