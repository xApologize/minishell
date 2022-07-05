#include "../include/minishell.h"

void	handle_echo(char *line, char **opt)
{
	if (check_n(opt[1]) == 1)
		print_echo_with_n(line);
	else
		print_echo_without_n(line);
}
