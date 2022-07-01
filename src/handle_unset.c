#include "../include/minishell.h"

void	handle_unset(char **opt, char **envp_copy)
{
	envp_copy = NULL;
	printf("%s\n", opt[0]);	
}
