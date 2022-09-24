#include "../include/minishell.h"

void	free_the_pp(char **pp)
{
	int	i;

	i = 0;
	if (!pp || !*pp)
		return ;
	while (pp[i])
	{
		free(pp[i]);
		pp[i] = NULL;
		i++;
	}
	free(pp);
	pp = NULL;
}
