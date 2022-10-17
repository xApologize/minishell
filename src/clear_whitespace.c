#include "../include/minishell.h"
extern char **g_envp_copy;

int	clear_whitespace(int i, char *str)
{
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i - 1);
}
