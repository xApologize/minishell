#include "../include/minishell.h"

// Implementation of env builtin
void	handle_env(char **opt, char **envp)
{
	int i;

	i = 0;
	if (opt[1] != NULL)
		dprintf(STDERR_FILENO, "env: too many arguments\n");
	else
		while (envp[i])
		{
			printf("%s\n", envp[i]);
			i++;
		}
}
