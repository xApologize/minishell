#include "../include/minishell.h"

bool	checkvalidenv(char *arg)
{
	int	i;

	i = 0;
	if (ft_isalpha(arg[0]) == 0)
		return (false);
	while (arg[i] != '=' && arg[i] != '\0')
	{
		if (ft_isalnum(arg[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}