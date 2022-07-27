#include "../include/minishell.h"

bool	checkvalidarg(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (ft_isalnum(arg[i]) == 0)
			return (false);
	}
	return (true);
}