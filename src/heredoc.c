#include "../include/minishell.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int		heredoc(t_data *data)
{
	int	fd;
	int	pid;

	fd = open("/tmp/minishell_heredoc.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (*data->line == '\0')
	{
		data->line++;
		data->indexmeta++;
	}
	sig_ignore();
	pid = fork();
	if (pid == 0)
	{
		sig_heredoc();
		start_heredoc(fd, data);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	while (*data->line != '\0')
		data->line++;
	close(fd);
	return (open("/tmp/minishell_heredoc.txt", O_RDONLY));
}

void	start_heredoc(int fd, t_data *data)
{
	char	*line;
	char	*return_line;

	while (1)
	{
		line = readline("> ");
		if (line == NULL || ft_strcmp(line, data->line) == 0)
			break ;
		return_line = ft_strjoin(line, "\n");
		write(fd , return_line, ft_strlen(return_line));
		free(line);
		free(return_line);
	}
	if (line)
		free(line);
	close(fd);
}
