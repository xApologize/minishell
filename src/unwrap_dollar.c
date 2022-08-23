#include "../include/minishell.h"

char *unwrap_dollar(char *line, char **envp_copy)
{
	char	*new_line;
	char	*value;

	new_line = ft_calloc(1, 1);
	while (*line)
	{
		if (*line == '\'')
			skip_single_quote(line);
		if (*line == '$')
		{
			value = return_dollar(line, envp_copy);
			new_line = ft_strjoinfree(new_line, value);
			free(value);
			line = skip_dollar(line);
		}
		new_line = charjoinfree(new_line, *line);
		line++;
	}
	return (new_line);
}