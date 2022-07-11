#include "../include/minishell.h"

char	*rl_gets(void)
{
	char	*line;

	line = readline("Minicougar>$ ");
	if (line && *line)
		add_history(line);
	line = ft_strjoinfree(line, "\n");
	return (line);
}