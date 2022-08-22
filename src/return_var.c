#include "../include/minishell.h"

char	*return_var(char *line)
{
	char	*var;
	char	token[5];

	var = malloc(1);
	token = "<>|\t ";
	line++;
	while (*line)
	{
		if (*line == ' ' || *line == '\t' || )
		var = charjoinfree(var, *line);
	}
}