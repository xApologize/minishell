#include "../include/minishell.h"

char	*return_var(char *line)
{
	char	*var;

	var = ft_calloc(1, 1);
	line++;
	while (*line)
	{
		if (ft_strchr("<>|\t ", *line))
			break ;
		var = charjoinfree(var, *line);
		line++;
	}
	return (var);
}