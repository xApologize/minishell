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
		// printf("cmd[%i]->redir_in: %i\n", j, tmp->redir_in);
		// printf("cmd[%i]->redir_out: %i\n", j, tmp->redir_out);
		// printf("cmd[%i]->cmd: %s\n", j, tmp->cmd);
		while (tmp->argv[i + 1] != NULL)
		{
			// printf("cmd[%i]->argv: %s\n", j, tmp->argv[i]);
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

	builtin = ft_calloc(9, sizeof(char*));
	builtin[0] = "echo";
	builtin[1] = "cd";
	builtin[2] = "pwd";
	builtin[3] = "export";
	builtin[4] = "unset";
	builtin[5] = "env";
	builtin[6] = "exit";
	builtin[7] = "pepe";
	builtin[8] = NULL;
	i = 0;
	while (builtin[i])
	{
		if (ft_strcmp(line, builtin[i]) == 0)
		{
			free(builtin);
			return(1);
		}
		i++;
	}
	free(builtin);
	return (0);
}

int	set_cmd(t_cmd *cmd)
{
	int		i;
	char	*line_cp;

	i = 0;
	line_cp = _data.line;
	if(is_builtin(line_cp) == 1)
	{
		cmd->is_builtin = 1;
		cmd->cmd = line_cp;
	}
	else
		cmd->cmd = get_path(line_cp);
	while (*line_cp != '\0')
		line_cp++;
	if (*line_cp == '\0' && ft_strchr(" \n", *_data.indexmeta))
		cmd->argv = get_argv();
	while (*_data.line != '\0')
		_data.line++;
	return (i - 1);
}

void	search_cmd(t_cmd *cmd)
{
	t_cmd	*tmp_cmd;

	tmp_cmd = cmd;
	while (*_data.indexmeta != '\0')
	{
		if (*_data.line == '\0' && ft_strchr("<>", *_data.indexmeta))
			get_fd(tmp_cmd, *_data.indexmeta);
		else if (*_data.line == '\0' && ft_strchr(" \n", *_data.indexmeta))
		{
			_data.indexmeta++;
			_data.line++;
		}
		else if (*_data.line == '\0' && *_data.indexmeta == '|')
		{
			tmp_cmd = tmp_cmd->next;
			_data.line++;
			_data.indexmeta++;
		}
		else
			set_cmd(tmp_cmd);
	}
	pipex(cmd);
	close_fd(cmd);
}

void	env_split(char **envp_copy)
{
	int	find;

	find = 0;
	_data.path_split = NULL;
	while (envp_copy[find])
	{
		if (ft_strncmp(envp_copy[find], "PATH=", 5) == 0)
			break ;
		find++;
	}
	if (envp_copy[find] != NULL)
		_data.path_split = ft_split(envp_copy[find], ':');
	_data.path_split[0] = _data.path_split[0] + 5;
}

void	trim_path(void)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(_data.path_split[0]);
	_data.path_split[0] = ft_substr(tmp, 5, ft_strlen(tmp));
	free(tmp);
	while (_data.path_split[i])
		i++;
}
