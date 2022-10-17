#include "../include/minishell.h"
extern char **g_envp_copy;

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