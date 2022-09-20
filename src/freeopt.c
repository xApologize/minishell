#include "../include/minishell.h"

void	freeopt(char **opt)
{
	int	i;

	i = 0;
	if (!*opt)
		return ;
	while (opt[i])
	{
		free(opt[i]);
		i++;
	}
	free(opt);
}