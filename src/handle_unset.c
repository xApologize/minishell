#include "../include/minishell.h"

// Unset without any options. Adding option triggers an error message. bash: unset: (option used): invalid option
//Error format for invalid identifier bash: unset: '%arg': not a valid identifier
char	**handle_unset(char **opt, char **envp_copy)
{
	int	i;

	i = 1;
	while (opt[i])
	{
		if (checkvalidarg(opt[i]))
		{
			dprintf(STDERR_FILENO, "msh: unset: '%s': not a valid identifier");
			i++;
		}
		else
		envp_copy
		
	}	
	return (envp_copy);
}
