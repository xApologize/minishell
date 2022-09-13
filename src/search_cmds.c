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
	int		i;
	int		j;

	tmp = cmd;
	i = 0;
	j = 0;
	while (tmp != NULL)
	{
		printf("cmd[%i]->redir_in: %i\n", j, tmp->redir_in);
		printf("cmd[%i]->redir_out: %i\n", j, tmp->redir_out);
		printf("cmd[%i]->cmd: %s\n", j, tmp->cmd);
		while (tmp->argv[i + 1] != NULL)
		{
			printf("cmd[%i]->argv: %s\n", j, tmp->argv[i]);
			i++;
		}
		i = 0;
		j++;
		tmp = tmp->next;
	}

}

void	set_fd_in(t_cmd *cmd, t_data *data)
{
	if (!cmd || !data)
		return ;
	while (*data->line == '\0' && ft_strchr(" <", *data->indexmeta))
	{
		data->line++;
		data->indexmeta++;
	}
	if (*data->line == '\0' && *data->indexmeta == ' ')
		return ;
	//printf("line in: %s\n", data->line);
	if (access(data->line, F_OK) == 0)
		cmd->redir_in = open(data->line, O_RDWR);
	//printf("cmd->redir_in: %i\n", cmd->redir_in);
	while (*data->line != '\0')
		data->line++;
}

void	set_fd_out(t_cmd *cmd, int append, t_data *data)
{
	if (!cmd || !data->line)
		return ;
	//printf("line out: %s\n", data->line);
	data->indexmeta++;
	if (append == 1)
		data->indexmeta++;
	while (*data->line == '\0' && (*data->indexmeta == ' ' || *data->indexmeta == '\0'))
	{
		data->line++;
		data->indexmeta++;
	}
	if (append == 0)
		cmd->redir_out = open(data->line, O_RDWR | O_CREAT, 0777);
	else
		cmd->redir_out = open(data->line, O_RDWR | O_APPEND | O_CREAT, 0777);
	//printf("cmd->redir_out: %i\n", cmd->redir_out);
	while (*data->line != '\0')
		data->line++;
}

char	*get_path(char *line_cp, t_data *data)
{
	int		i;
	char	*slash;
	char	*access_try;

	i = 0;
	slash = ft_strjoin("/", line_cp);
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

int	get_argv_count(t_data *data)
{
	char	*line_cp;
	char	*indexmeta_cp;
	int		argv_count;

	line_cp = data->line;
	indexmeta_cp = data->indexmeta;
	argv_count = 1;
	while (*indexmeta_cp != '\0')
	{
		if (*line_cp == '\0' && ft_strchr("<>|\n", *indexmeta_cp))
			break ;
		if (*line_cp == '\0' && ft_strchr(" \n", *data->indexmeta))
		{
			while (*line_cp == '\0' && *indexmeta_cp == ' ')
			{
				line_cp++;
				indexmeta_cp++;
			}
			argv_count++;
		}
		line_cp++;
	}
	return (argv_count);
}

char	**get_argv(t_data *data)
{
	int		argv_count;
	int		i;
	char	**argv;

	argv_count = get_argv_count(data);
	argv = ft_calloc(sizeof(char*),  argv_count + 1);
	i = 0;
	while (!ft_strchr("<>|\n", *data->indexmeta))
	{
		if (i == 0)
		{
			argv[i] = ft_strdup(data->line);
			i++;
		}
		if (*data->line == '\0' && ft_strchr(" \n", *data->indexmeta))
		{
			while (*data->line == '\0' && *data->indexmeta == ' ')
			{
				data->line++;
				data->indexmeta++;
			}
			argv[i] = ft_strdup(data->line);
			i++;
		}
		else 
			data->line++;
	}
	if (i == 0)
		argv[i] = ft_strdup(data->line);
	return (argv);
}

int	set_cmd(t_cmd *cmd, t_data *data)
{
	int		i;
	char	*line_cp;

	i = 0;
	line_cp = data->line;
	//printf("set_cmd line: %s\n", data->line);
	cmd->cmd = get_path(line_cp, data);
	while (*line_cp != '\0')
		line_cp++;
	if (*line_cp == '\0' && ft_strchr(" \n", *data->indexmeta))
		cmd->argv = get_argv(data);
	while (*data->line != '\0')
		data->line++;
	return (i - 1);
}

void	get_fd(t_cmd *cmd, t_data *data, char meta)
{
	if (meta == '<')
	{
		if (data->line[1] == '\0' && data->indexmeta[1] == '<')
			cmd->redir_in = heredoc(data);
		else
			set_fd_in(cmd, data);
	}
	else if (meta == '>')
	{
		if (data->line[1] == '\0' && data->indexmeta[1] == '>')
			set_fd_out(cmd, 1, data);
		else
			set_fd_out(cmd, 0, data);
	}
}

void	search_cmd(t_data *data, t_cmd *cmd)
{
	t_cmd	*tmp_cmd;

	tmp_cmd = cmd;
	while (*data->indexmeta != '\0')
	{
		if (*data->line == '\0' && ft_strchr("<>", *data->indexmeta))
			get_fd(tmp_cmd, data, *data->indexmeta);
		else if (*data->line == '\0' && ft_strchr(" \n", *data->indexmeta))
		{
			data->indexmeta++;
			data->line++;
		}
		else if (*data->line == '\0' && *data->indexmeta == '|')
		{
			tmp_cmd = tmp_cmd->next;
			data->line++;
			data->indexmeta++;
		}
		else
			set_cmd(tmp_cmd, data);
	}
	pipex(cmd);
}

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
