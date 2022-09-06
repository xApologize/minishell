#include "../include/minishell.h"
#include <stdio.h>

t_cmd	*set_exec_struct(t_data *data, char **env)
{
	int		i;
	int		noeud;
	t_cmd	*list;

	i = 0;
	noeud = nb_pipes(data);
	list = NULL;
	while ( i < noeud)
	{
		add_nodes(&list, create_nodes(env));
		i++;
	}
	return (list);
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
	node->redir_in = PIPE_READ;
	node->redir_out = PIPE_WRITE;
	node->cmd = "patate";
	node->env = env;
	node->next = NULL;
	return (node);
}

void add_nodes(t_cmd **cmd, t_cmd *new_cmd)
{
	t_cmd *last;

	if (!*cmd)
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
