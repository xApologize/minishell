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
	while (tmp != NULL)
	{
		printf("cmd: %s\n", tmp->cmd);
		tmp = tmp->next;
	}

}

void	set_fd_in(t_cmd *cmd, char *line_cp)
{
	if (!cmd || !line_cp)
		return ;
	printf("line in: %s\n", line_cp);
	if (access(line_cp, F_OK) == 0)
		cmd->redir_in = open(line_cp, O_RDWR);
	printf("cmd->redir_in: %i\n", cmd->redir_in);
}

void	set_fd_out(t_cmd *cmd, int append, t_data *data)
{
	if (!cmd || !data->line)
		return ;
	printf("line out: %s\n", data->line);
	if (append == 0)
		cmd->redir_out = open(data->line, O_RDWR | O_CREAT, 0777);
	else
	{
		cmd->redir_out = open(data->line, O_RDWR | O_APPEND | O_CREAT, 0777);
		data->indexmeta++;
	}
	printf("cmd->redir_out: %i\n", cmd->redir_out);
}

char	*get_path(t_data *data)
{
	int		i;
	char	*slash;
	char	*access_try;

	i = 0;
	slash = ft_strjoin("/", data->line);
	while (data->path_split[i] != NULL)
	{
		access_try = ft_strjoin(data->path_split[i], slash);
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

char	**get_argv(t_data *data)
{
	char	*line_cp;
	char	*indexmeta_cp;
	int		argv_count;

	line_cp = data->line;
	indexmeta_cp = data->indexmeta;
	argv_count = 1;
	while (*indexmeta_cp != '\0')
	{
		if (*line_cp == '\0' && ft_strchr("<>|", *indexmeta_cp))
			break ;
		if (*line_cp == '\0' && *indexmeta_cp == ' ')
		{
			indexmeta_cp++;
			argv_count++;
		}
		line_cp++;
	}
	printf("argv_count: %i\n", argv_count);
	return (NULL);
}

int	set_cmd(t_cmd *cmd, t_data *data)
{
	int		i;
	char	*line_cp;

	i = 0;
	line_cp = data->line;
	printf("set_cmd line: %s\n", data->line);
	cmd->cmd = get_path(data);
	while (*data->line != '\0')
		data->line++;
	if (*data->line == '\0' && data->indexmeta[0] == ' ')
	{
		printf("argv!\n");
		cmd->argv = get_argv(data);
	}
	while (*data->line != '\0')
		data->line++;
	return (i - 1);
}

void	get_fd(t_cmd *cmd, t_data *data)
{
	int		i;

	i = 0;
	while (*data->line == '\0')
	{
		data->line++;
		i++;
	}
	if (data->indexmeta[0] == '<')
	{
		if (data->line[1] == '\0' && data->indexmeta[1] == '<')
			cmd->redir_in = heredoc(data->line, data);
		else
			set_fd_in(cmd, data->line);
	}
	else if (data->indexmeta[0] == '>')
	{
		if (data->line[1] == '\0' && data->indexmeta[1] == '>')
			set_fd_out(cmd, 1, data);
		else
			set_fd_out(cmd, 0, data);
	}
	data->indexmeta += i;
	while (*data->line != '\0')
		data->line++;
}

void	search_cmd(t_data *data, t_cmd *cmd)
{
	int		i;
	t_cmd	*tmp_cmd;

	i = 0;
	tmp_cmd = cmd;
	while (i < data->line_lenght)
	{
		if (*data->line == '\0' && data->indexmeta[0] == '\0')
			break ;
		if (*data->line == '\0' && ft_strchr("<>", data->indexmeta[0]))
			get_fd(tmp_cmd, data);
		else if (*data->line == '\0' && data->indexmeta[0] == ' ')
			data->indexmeta++;
		else if (*data->line == '\0' && data->indexmeta[0] == '|')
		{
			tmp_cmd = tmp_cmd->next;
			data->indexmeta++;
		}
		else
			set_cmd(tmp_cmd, data);
		i++;
		data->line++;
	}
	print_struct(cmd);
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
	data->path_split[0] = data->path_split[0] + 5;
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
