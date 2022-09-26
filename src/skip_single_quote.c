#include "../include/minishell.h"

void	skip_single_quote(char *line)
{
	while (*line != '\'' && *line != '\0')
	{
		line++;
	}
	line++;
}
