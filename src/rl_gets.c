#include "../include/minishell.h"

//uses readline to get input from stdin. Adds the line to history
char	*rl_gets(void)
{
	char	*line;
	char	*backslash;

	printf("\033[0;37m");
	line = readline("minicougar>$ ");
	backslash = ft_strjoinfree(line, "\n");
	if (line && *line)
		add_history(line);
	return (backslash);
}
