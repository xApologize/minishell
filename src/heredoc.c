#include "../include/minishell.h"
#include <stdlib.h>
#include <unistd.h>

int	heredoc(char *delimiter, t_data *data)
{
	char	*line;
	char	*return_line;
	int		fd[2];

	pipe(fd);
	while (1)
	{
		line = readline("> ");
		if (ft_strcmp(line, delimiter) == 0)
			break ;
		return_line = ft_strjoin(line, "\n");
		write(fd[1], return_line, ft_strlen(return_line));
		free(line);
		free(return_line);
	}
	free(line);
	data->indexmeta++;
	return (fd[1]);
}
