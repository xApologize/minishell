/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:19:09 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:19:11 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

int	heredoc(t_data *data)
{
	int		fd;
	int		pid;
	char	*placeholder;

	fd = open("/tmp/minishell_heredoc.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (*data->line == '\0')
		skip_char(data);
	placeholder = stripstring(ft_strdup(data->line));
	sig_ignore();
	pid = fork();
	if (pid == 0)
	{
		sig_heredoc();
		start_heredoc(fd, placeholder);
		close(data->stdin_cp);
		close(data->stdout_cp);
		free_the_pp(g_envp_copy);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	free(placeholder);
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
		write(fd, return_line, ft_strlen(return_line));
		free(return_line);
		free(line);
	}
	if (line)
		free(line);
	close(fd);
}
