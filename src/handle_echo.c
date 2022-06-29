#include "../include/minishell.h"

void	handle_echo(char *line, char **opt)
{
	if (ft_strcmp(opt[1], "-n") == 0)
		print_echo_with_n(line);
	else
		print_echo_without_n(line);
}
