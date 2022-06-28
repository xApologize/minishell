#include "../include/minishell.h"

void	handle_echo(char **opt)
{
	printf("%s", opt[0]);
}