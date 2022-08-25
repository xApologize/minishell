#include "../include/minishell.h"

// void	set_exec_struct(char *line, t_cmd *cmd, t_data *data, char **env)
// {
// 	int		i;
// 	int		noeud;

// 	i = 0;
// 	cmd = NULL;
// 	noeud = nb_pipes(data);
// 	while (noeud > i++)
// 	{
// 		add_nodes(&cmd, create_nodes(cmd, argv, env));
// 	}
// 	while (i < data->line_lenght)
// 	{
// 		line[i];
// 	}
// }

// int	nb_pipes(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (data->indexmeta[i] != '\0')
// 	{
// 		if (data->indexmeta[i] == '|')
// 			j++;
// 		i++;
// 	}
// 	return (j + 1);
// }

// t_cmd *create_nodes(char *cmd, char **argv, char **env)
// {
// 	t_cmd *node;

// 	node = malloc(sizeof(t_cmd));
// 	if (!node)
// 		return(NULL);
// 	node->cmd = cmd;
// 	node->argv = argv;
// 	node->environ = env;
// 	node->next = NULL;
// 	return (node);
// }

// void add_nodes(t_cmd **cmd, t_cmd *new_cmd)
// {
// 	t_cmd *last;

// 	if (cmd == NULL)
// 		cmd = new_cmd;
// 	else
// 	{
// 		last = ft_lstlast(*cmd);
// 		last->next = new_cmd;
// 	}
// }

// // malloc cmd = pipex split_path