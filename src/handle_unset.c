#include "../include/minishell.h"

// Unset without any options. Adding option triggers an error message. bash: unset: (option used): invalid option
void	handle_unset(char **opt, char **envp_copy)
{
	access(envp_copy[0], F_OK);
	printf("%s\n", opt[0]);	
}
