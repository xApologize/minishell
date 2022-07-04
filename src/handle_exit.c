#include "../include/minishell.h"

void	handle_exit(char *line, char **opt, char **envp_copy)
{
	if (line != NULL)
		free(line);
	freeopt(opt);
	freeopt(envp_copy);
	exit(0);
}