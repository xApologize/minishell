#include "../include/minishell.h"

char	*handle_dollar(char *line)
{
	char	*new_line;

	if (check_dollar(line))
	{
		new_line = unwrap_dollar(line);
		return (new_line);
	}
	return (line);
}