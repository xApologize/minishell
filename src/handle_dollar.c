#include "../include/minishell.h"

char *handle_dollar(char *line, char **envp_copy)
{
	char *new_line;
	if (check_dollar(line))
	{
		new_line = unwrap_dollar(line, envp_copy);
		return (new_line);
	}
	return (line);
}