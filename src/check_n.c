#include "../include/minishell.h"

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
