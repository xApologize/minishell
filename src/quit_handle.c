#include "../include/minishell.h"

void	quit_handling(int signum)
{
	if (signum == 3)
	{
		write(1, "Quit\n", 5);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}