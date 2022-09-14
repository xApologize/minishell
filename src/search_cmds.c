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

int	is_builtin(char *line)
{
	char	**builtin;
	int		i;

	builtin = ft_calloc(8, sizeof(char*));
	builtin[0] = "echo";
	builtin[1] = "cd";
	builtin[2] = "pwd";
	builtin[3] = "export";
	builtin[4] = "unset";
	builtin[5] = "env";
	builtin[6] = "exit";
	i = 0;
	while (builtin[i])
	{
		if (ft_strcmp(line, builtin[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	set_cmd(t_cmd *cmd, t_data *data)
{
	int		i;
	char	*line_cp;

	i = 0;
	line_cp = data->line;
	if(is_builtin(line_cp) == 1)
	{
		printf("is_builtin\n");
		cmd->is_builtin = 1;
		cmd->cmd = line_cp;
	}
	else
		cmd->cmd = get_path(line_cp, data);
	printf("cmd.is_builtin: %i\n", cmd->is_builtin);
	while (*line_cp != '\0')
		line_cp++;
	if (*line_cp == '\0' && ft_strchr(" \n", *data->indexmeta))
		cmd->argv = get_argv(data);
	while (*data->line != '\0')
		data->line++;
	return (i - 1);
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
