#include "../include/minishell.h"

//join strings together separated by a line space
char	*make_line(char **argv)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_calloc(1, 1);
	while (argv[i])
	{
		if (argv[i][0] == '\'' || argv[i][0] == '"')
			argv[i] = ft_strtrimfree(argv[i], "'\"");
		line = ft_strjoinfree(line, argv[i]);
		if (argv[i + 1] == NULL)
			break ;
		line = ft_strjoinfree(line, " ");
		i++;
	}
	return (line);
}
