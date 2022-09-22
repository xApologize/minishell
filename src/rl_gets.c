#include "../include/minishell.h"

char	*rl_gets(void)
{
	char	*line;
	char	*backslash;

	line = readline("Minicougar>$ ");
	backslash = ft_strjoin(line, "\n");
	if (line && *line)
		add_history(line);
	free(line);
	return (backslash);
}
