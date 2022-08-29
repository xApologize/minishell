#include "../include/minishell.h"

void	set_exec_struct(char *line, t_cmd *cmd, t_data *data, char **env)
{
	int		i;
	int		noeud;

	i = 0;
	(void)line;
	noeud = nb_pipes(data);
	while (i < noeud)
	{
		add_nodes(&cmd, create_nodes(env));
		i++;
	}
}

int	nb_pipes(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->indexmeta[i] != '\0')
	{
		if (data->indexmeta[i] == '|')
			j++;
		i++;
	}
	return (j + 1);
}

t_cmd *create_nodes(char **env)
{
	t_cmd *node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		return(NULL);
	node->env = env;
	node->next = NULL;
	return (node);
}

void add_nodes(t_cmd **cmd, t_cmd *new_cmd)
{
	t_cmd *last;

	if (*cmd == NULL)
		*cmd = new_cmd;
	else
	{
		last = get_last(*cmd);
		last->next = new_cmd;
	}
}

t_cmd *get_last(t_cmd *cmd)
{
	t_cmd *tmp;

	tmp = cmd;
	if (!cmd)
		return(NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

// malloc cmd = pipex split_path
