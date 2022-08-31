#include "../include/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <unistd.h>

void	print_struct(t_cmd *cmd)
{
	t_cmd *tmp;

	tmp = cmd;
	printf("print struct!\n");
	printf("cmd: %s\n", tmp->cmd);
	printf("cmd1: %s\n", tmp->next->cmd);

}

void	set_fd_in(t_cmd *cmd, char *line)
{
	if (!cmd || !line)
		return ;
	if (access(line, F_OK) == 0)
		cmd->redir_in = open(line, O_RDWR);
}

void	set_fd_out(t_cmd *cmd, char *line, int append, t_data *data)
{
	if (!cmd || !line)
		return ;
	if (append == 0)
		cmd->redir_out = open(line, O_RDWR | O_CREAT, 0777);
	else
	{
		cmd->redir_out = open(line, O_RDWR | O_APPEND | O_CREAT, 0777);
		data->indexmeta++;
	}
}

char	*get_path(char *line, t_data *data)
{
	int		i;
	char	*slash;
	char	*access_try;

	i = 0;
	printf("line: %s\n", line);
	slash = ft_strjoin("/", line);
	while (data->path_split[i] != NULL)
	{
		access_try = ft_strjoin(data->path_split[i], slash);
		printf("access_try: %s\n", access_try);
		if (access(access_try, X_OK) == 0)
		{
			free(slash);
			return (access_try);
		}
		i++;
		free(access_try);
	}
	return (NULL);
}

int	set_cmd(t_cmd *cmd, char *line, t_data *data)
{
	int		i;
	char	*line_cp;

	i = 0;
	line_cp = line;
	while (line[i++] == '\0' && data->indexmeta[0] != '\0')
		line_cp++;
	cmd->cmd = get_path(line_cp, data);
	return (i);
}

int	get_fd(t_cmd *cmd, char *line, t_data *data)
{
	int		i;
	char	*line_cp;

	i = 0;
	line_cp = line;
	while (line[i++] == '\0' && data->indexmeta[0] != '\0')
		line_cp++;
	if (data->indexmeta[0] == '<')
	{
		if (line[1] == '\0' && data->indexmeta[1] == '<')
			cmd->redir_in = heredoc(line_cp, data);
		else
			set_fd_in(cmd, line_cp);
	}
	else if (data->indexmeta[0] == '>')
	{
		if (line[1] == '\0' && data->indexmeta[1] == '>')
			set_fd_out(cmd, line_cp, 1, data);
		else
			set_fd_out(cmd, line_cp, 0, data);
	}
	data->indexmeta++;
	return (i);
}

void	search_cmd(t_data *data, char *line, t_cmd *cmd)
{
	int		i;
	t_cmd	*tmp_cmd;

	i = 0;
	tmp_cmd = cmd;
	while (i < data->line_lenght)
	{
		if (*line == '\0' && ft_strchr("<>", data->indexmeta[0]))
			line += get_fd(tmp_cmd, line, data);
		else if (*line == '\0' && data->indexmeta[0] == ' ')
			line += set_cmd(cmd, line, data);
		else if (*line == '\0' && data->indexmeta[0] == '|')
			tmp_cmd = tmp_cmd->next;
		i++;
		line++;
	}
}

// void	search_cmd(t_data *data, char *line, t_cmd *cmd)
// {
// 	int		i;
// 	char	*cmd_join;
// 	int		j;
// 	int		check;
// 	char	*check_path;
// 	int		k;
// 	char 	*l;
// 	t_cmd	*tampax;
//
// 	i = 0;
// 	j = 0;
// 	check = 0;
// 	k = 0;
// 	l = line;
// 	tampax = cmd;
// 	printf("line lenght = %d\n", data->line_lenght);
// 	while (i < data->line_lenght)
// 	{
// 		data->redir_bool = 0;
// 		while (line[i] != '\0')
// 			i++;
// 		cmd_join = ft_strjoin("/", l);
// 		l = line + (i + 1);
// 		printf("cmdjoin: %s|\n", cmd_join);
// 		printf("l = %s\n", l);
// 		while (!ft_strchr("<>|", data->indexmeta[j]) && !l)
// 		{
// 			l++;
// 			j++;
// 			i++;
// 			if (ft_strchr("<>|", data->indexmeta[j]))
// 			{
// 				data->redir_bool = 1;
// 				break ;
// 			}
// 		}
// 		while (data->path_split[k] != NULL)
// 		{
// 			check_path = ft_strjoin(data->path_split[k], cmd_join);
// 			printf("check_path = %s|\n", check_path);
// 			if (access(check_path, X_OK) == 0)
// 			{			
// 				tampax->cmd = check_path;
// 				if (data->redir_bool == 1)
// 					tampax = tampax->next;
// 				break ;
// 			}
// 			else
// 				k++;
// 		}
// 		k = 0;
// 		i++;
// 	}
// 	print_struct(cmd);
// }



void	env_split(t_data *data, char **envp_copy)
{
	int	find;

	find = 0;
	data->path_split = NULL;
	while (envp_copy[find])
	{
		if (ft_strncmp(envp_copy[find], "PATH=", 5) == 0)
			break ;
		find++;
	}
	if (envp_copy[find] != NULL)
		data->path_split = ft_split(envp_copy[find], ':');
}

void	trim_path(t_data *data)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(data->path_split[0]);
	data->path_split[0] = ft_substr(tmp, 5, ft_strlen(tmp));
	free(tmp);
	while (data->path_split[i])
		i++;
}
