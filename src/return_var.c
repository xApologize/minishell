#include "../include/minishell.h"

char	*return_var(char *line)
{
	char	*var;

	var = malloc(1);
	line++;
	while (*line)
	{
		if (ft_strchr("<>|\t ", *line))
			break ;
		var = charjoinfree(var, *line);
		line++;
	}
	var = charjoinfree(var, '\0');
	return (var);
}