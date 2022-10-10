#include "../include/minishell.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int		heredoc(t_data *data)
{
	int	fd;
	int	pid;

	fd = open("/tmp/minishell_heredoc.txt", O_CREAT | O_TRUNC | O_RDWR, 0777);
	while (*data->line == '\0')
	{
		data->line++;
		data->indexmeta++;
	}
	pid = fork();
	if (pid == 0)
	{
		sig_reset();
		start_heredoc(fd, data);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	while (*data->line != '\0')
		data->line++;
	return (fd);
}

void	start_heredoc(int fd, t_data *data)
{
	char	*line;
	char	*return_line;

	while (1)
	{
		line = readline("> ");
		if (line == NULL || ft_strcmp(line, data->line) == 0)
		{
			free(line);
			break ;
		}
		return_line = ft_strjoin(line, "\n");
		write(fd , return_line, ft_strlen(return_line));
		free(line);
		free(return_line);
	}
	//close(fd);
}
