#include "../include/minishell.h"

// Implementation of env builtin
void	handle_env(char **argv, char **envp_copy)
{
	int i;

	i = 0;
	if (argv[1] != NULL)
		dprintf(STDERR_FILENO, "env: %s: No such file or directory\n", argv[1]);
	else
		while (envp_copy[i])
		{
			printf("%s\n", envp_copy[i]);
			i++;
		}
}
