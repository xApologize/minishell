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
//
// int main()
// {
// 	set_exit_code(123);
// 	int	*exit_code = get_exit_code();
// 	printf("first: %i", *exit_code);
// 	set_exit_code(116);
// 	exit_code = get_exit_code();
// 	printf("second: %i", *exit_code);
// }
