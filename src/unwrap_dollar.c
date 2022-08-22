#include "../include/minishell.h"

char *unwrap_dollar(char *line, char **envp_copy)
{
	char	*new_line;

	new_line = malloc(1);
	while (*line)
	{
		if (*line == '\'')
			skip_single_quote(line);
		if (*line == '$')
		{
			new_line = ft_strjoinfree(new_line, return_dollar(line, envp_copy));
			skip_dollar(line);
		}
		new_line = charjoinfree(new_line, *line);
		line++;
	}
	return (new_line);
}