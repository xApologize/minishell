#include "../include/minishell.h"

int	heredoc(void)
{
	char	*line;
	char	*return_line;
	int		fd[2];

	pipe(fd);
	while (*_data.line == '\0')
	{
		_data.line++;
		_data.indexmeta++;
	}
	while (1)
	{
		line = readline("> ");
		if (ft_strcmp(line, _data.line) == 0)
			break ;
		return_line = ft_strjoin(line, "\n");
		write(fd[1], return_line, ft_strlen(return_line));
		free(line);
		free(return_line);
	}
	free(line);
	while (*_data.line != '\0')
		_data.line++;
	return (fd[1]);
}
