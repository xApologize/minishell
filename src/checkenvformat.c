#include "../include/minishell.h"

int	checkenvformat(char *var)
{
	int	i;

	i = -1;
	while (var[++i])
	{
		if (var[i] == '=' && \
		ft_isprint(var[i - 1]) == 1 && ft_isprint(var[i + 1]) == 1)
			return (1);
	}
	return (0);
}
