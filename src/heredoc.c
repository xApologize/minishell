#include "../include/minishell.h"

int	heredoc(t_data *data)
{
	char	*line;
	char	*return_line;
	int		fd[2];

	pipe(fd);
	while (*data->line == '\0')
	{
		data->line++;
		data->indexmeta++;
	}
	while (1)
	{
		line = readline("> ");
		if (ft_strcmp(line, data->line) == 0)
			break ;
		return_line = ft_strjoin(line, "\n");
		write(fd[1], return_line, ft_strlen(return_line));
		free(line);
		free(return_line);
	}
	free(line);
	while (*data->line != '\0')
		data->line++;
	return (fd[1]);
}
