#include "../include/minishell.h"

bool checkassign(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (ft_isalnum(arg[i]) == 1 && arg[i + 1] == '=')
			return (true);
	}
	return (false);
}