#include "../include/minishell.h"

void	quit_handler(int signum)
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

void	sigint_handler(int signum)
{
	struct termios	termios_copy;
	struct termios	termios_repl;

	tcgetattr(0, &termios_copy);
	termios_repl = termios_copy;
	termios_repl.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &termios_repl);
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	shush_handler(int signum)
{
	struct termios	termios_copy;
	struct termios	termios_repl;

	tcgetattr(0, &termios_copy);
	termios_repl = termios_copy;
	termios_repl.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &termios_repl);
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	hd_handler(int signum)
{
	struct termios	termios_copy;
	struct termios	termios_repl;

	tcgetattr(0, &termios_copy);
	termios_repl = termios_copy;
	termios_repl.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &termios_repl);
	if (signum == SIGINT)
	{
		unlink("/tmp/minishell_heredoc.txt");
		exit(0);
	}
}