#include "../include/minishell.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int		heredoc(t_data *data)
{
	int		fd;
	int		pid;

	fd = open("/tmp/minishell_heredoc.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (*data->line == '\0')
		skip_char(data);
	sig_ignore();
	pid = fork();
	if (pid == 0)
	{
		sig_heredoc();
		start_heredoc(fd, stripstring(ft_strdup(data->line)));
		exit(0);
	}
	waitpid(pid, NULL, 0);
	while (*data->line != '\0')
		data->line++;
	close(fd);
	return (open("/tmp/minishell_heredoc.txt", O_RDONLY));
}

void	start_heredoc(int fd, char *delim)
{
	char	*line;
	char	*return_line;

	while (1)
	{
		line = readline("> ");
		if (line == NULL || ft_strcmp(line, delim) == 0)
			break ;
		return_line = ft_strjoin(line, "\n");
		return_line = handle_dollar(return_line, 1);
		write(fd , return_line, ft_strlen(return_line));
		free(line);
		free(return_line);
	}
	if (line)
		free(line);
	close(fd);
}
