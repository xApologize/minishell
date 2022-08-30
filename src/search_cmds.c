#include "../include/minishell.h"
#include <stdio.h>
#include <strings.h>
#include <sys/fcntl.h>
#include <unistd.h>

void	print_struct(t_cmd *cmd)
{
	t_cmd *tmp;

	tmp = cmd;
	printf("print struct!\n");
	printf("cmd: %s\n", tmp->cmd);
	printf("cmd1: %s\n", tmp->next->cmd);

}

int	set_fd(t_cmd *cmd, char *line, t_data *data)
{
	int		i;
	char	c;
	char	*line_cp;

	i = 0;
	c = data->indexmeta[0];
	cmd = NULL;
	line_cp = line;
	while (line[i] == '\0' && data->indexmeta[0] != '\0')
	{
		line_cp++;
		i++;
	}
	if (c == '<')
	{
		if (line[1] == '\0' && data->indexmeta[1] == '<')
		{
			printf("heredoc delim: %s\n", line_cp);
			data->indexmeta++;
		}
		else
			printf("redir input file: %s\n", line_cp);
	}
	else if (c == '>')
	{
		if (line[1] == '\0' && data->indexmeta[1] == '>')
		{
			printf("redir output append file: %s\n", line_cp);
			data->indexmeta++;
		}
		else
			printf("redir output file: %s\n", line_cp);
	}
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
		// if (line[i] == '\0' && ft_strchr("<>", data->indexmeta[0]))
		if (*line == '\0' && ft_strchr("<>", data->indexmeta[0]))
		{
			//i += set_fd(tmp_cmd, line, data)
			line += set_fd(tmp_cmd, line, data);
			// line += set_fd(tmp_cmd, line, data);
			data->indexmeta++;
		}
		else if (*line == '\0' && data->indexmeta[0] == ' ')
			data->indexmeta++;
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
