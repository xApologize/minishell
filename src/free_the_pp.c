#include "../include/minishell.h"

void	free_the_pp(char **opt)
{
	int	i;

	i = 0;
	if (!opt || !*opt)
		return ;
	while (opt[i])
	{
		free(opt[i]);
		opt[i] = NULL;
		i++;
	}
	free(opt);
	opt = NULL;
}
