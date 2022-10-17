#include "../include/minishell.h"
extern char **g_envp_copy;

//uses readline to get input from stdin. Adds the line to history
char	*rl_gets(void)
{
	char	*line;
	char	*backslash;

	printf("\033[0;37m");
	line = readline("minicougar>$ ");
	if (line && *line)
		add_history(line);
	backslash = ft_strjoinfree(line, "\n");
	return (backslash);
}
