#include "../include/minishell.h"
#include <stdio.h>
#include <unistd.h>

void	print_struct(t_cmd *cmd)
{
	t_cmd	*tmp;
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

	builtin = ft_calloc(9, sizeof (char *));
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
			return (1);
		}
		i++;
	}
	free(builtin);
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
		cmd->is_builtin = 1;
		cmd->cmd = ft_strdup(line_cp);
	}
	else
		cmd->cmd = get_path(line_cp, data);
	while (*line_cp != '\0')
		line_cp++;
	cmd->argv = get_argv(data);
	while (*data->line != '\0')
		data->line++;
	return (i - 1);
}

void	search_cmd(t_data *data, t_cmd *cmd)
{
	t_cmd	*tmp_cmd;

	tmp_cmd = cmd;
	quiet_handling();
	while (*data->indexmeta != '\0')
	{
		if (*data->line == '\0' && ft_strchr("<>", *data->indexmeta))
			get_fd(tmp_cmd, data, *data->indexmeta);
		else if (*data->line == '\0' && ft_strchr(" \n", *data->indexmeta))
			skip_char(data);
		else if (*data->line == '\0' && *data->indexmeta == '|')
		{
			tmp_cmd = tmp_cmd->next;
			skip_char(data);
		}
		else
			set_cmd(tmp_cmd, data);
	}
	if (cmd->is_builtin == 1 && cmd->next == NULL)
		handle_single_builtin(cmd, data);
	else
		pipex(cmd, data);
	close_fd(cmd);
	free_data_cmd(cmd, data);
}
