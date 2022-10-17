#include "../include/minishell.h"

extern char	**g_envp_copy;

//join strings together separated by a line space
char	*make_line(char **argv)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_calloc(1, 1);
	while (argv[i])
	{
		line = ft_strjoinfree(line, argv[i]);
		if (argv[i + 1] == NULL)
			break ;
		line = ft_strjoinfree(line, " ");
		i++;
	}
	return (line);
}
