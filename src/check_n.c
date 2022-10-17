#include "../include/minishell.h"

extern char	**g_envp_copy;

//checks if argument contains -n option. Works with multiple chained n's
int	check_n(char *opt)
{
	int	i;

	i = 0;
	if (opt[0] != '-')
		return (0);
	else
	{
		while (opt[++i])
			if (opt[i] != 'n')
				return (0);
	}
	return (1);
}
