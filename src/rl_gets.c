#include "../include/minishell.h"

char	*rl_gets(void)
{
	char	*line;
	char	*backslash;

	printf("\033[0;37m");
	line = readline("Minicougar>$ ");
	backslash = ft_strjoin(line, "\n");
	if (line && *line)
		add_history(line);
	free(line);
	return (backslash);
}
