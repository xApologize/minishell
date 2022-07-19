#include "../include/minishell.h"

void	sig_reset(void)
{
	struct sigaction sa_sigint;
	struct sigaction sa_sigquit;

	sa_sigint.sa_handler = NULL;
	sa_sigquit.sa_handler = NULL;
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = SA_RESETHAND;
	sa_sigquit.sa_flags = SA_RESETHAND;
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}