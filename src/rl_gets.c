#include "../include/minishell.h"

char	*rl_gets(void)
{
	char	*line;

	line = readline("Minicougar>$");
	if (line && *line)
		add_history(line);
	return (line);
}