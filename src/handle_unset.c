#include "../include/minishell.h"

void	handle_unset(char **opt, char **envp_copy)
{
	access(envp_copy[0], F_OK);
	printf("%s\n", opt[0]);	
}
