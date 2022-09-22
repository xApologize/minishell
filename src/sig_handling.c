#include "../include/minishell.h"

void	sig_handling(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = sigint_handler;
	sa_sigquit.sa_handler = SIG_IGN;
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}
