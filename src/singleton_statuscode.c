#include "../include/minishell.h"
#include <stdio.h>
#include <sys/wait.h>

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
