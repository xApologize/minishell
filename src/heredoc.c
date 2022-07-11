#include "../include/minishell.h"
#include <stdlib.h>

void	heredoc(char *delimiter, int fd)
{
	char	*line;
	char	*return_line;

	while (1)
	{
		line = readline("> ");
		if (ft_strcmp(line, delimiter) == 0)
			break ;
		return_line = ft_strjoin(line, "\n");
		write(fd, return_line, ft_strlen(return_line));
		free(line);
		free(return_line);
	}
	free(line);
}
