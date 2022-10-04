#include "../include/minishell.h"

//rewires sigint and sigquit
void	sig_handling(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = sigint_handler;
	sa_sigint.sa_mask = 0;
	sa_sigquit.sa_handler = SIG_IGN;
	sa_sigquit.sa_mask = 0;
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

void	quiet_handling(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = shush;
	sa_sigint.sa_mask = 0;
	sa_sigquit.sa_handler = quit_handling;
	sa_sigquit.sa_mask = 0;
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

//reset sigint and sigquit to their original state
void	sig_reset(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = NULL;
	sa_sigquit.sa_handler = NULL;
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = SA_RESETHAND;
	sa_sigquit.sa_flags = SA_RESETHAND;
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

//handler function for sigint
void	sigint_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	shush(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}
