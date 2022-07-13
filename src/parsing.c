#include "../include/minishell.h"

void	parsing(char *line, char **envp_copy, t_data *data)
{
	DEBUG;
	access(envp_copy[0], F_OK);
	find_cmds(line, data);
	env_split(data, envp_copy);
	check_first(line, data);
	search_cmd(data);
	//error_quotation(data);
}

void	find_cmds(char *line, t_data *data)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	data->nb_tab = find_nb_tb(line);
	printf("nb_tab = %d\n", data->nb_tab);
	data->cmd_tab = (char **)malloc(sizeof(data->nb_tab) + 1);
	// while (line[i])
	// {
	// 	if (line[i] == '\"' || line[i] == '\'')
	// 		tokenize_quotes(line, data);
	// 	if ((line[i] >= 9 && line[i] <= 13) || (line[i] == 32 && quotes != 1))
	// 	{
	// 		while ()
	// 		i++;
	// 	}
	// }
}

// void	split_whitespaces(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (data->line_split[i])
// 	{
// 		data->line_split[i] = check_quotes(data->line_split[i]);
// 	}
// }

// void	tokenize_quote(char *line, t_data *data)
// {

// }

// char	*check_quotes(char *line)
// {
// 	int	i;
// 	int	count_quote;

// 	i = 0;
// 	count_quote = 0;
// 	while (line[i] != '\0')
// 	{
// 		if (line[i] == '\'')
// 			count_quote++;
// 		i++;
// 	}
// 	if ((count_quote % 2) == 0)
// 	{
// 		if (count_quote == 2 && count_quote != 0)
			
// 	}
// }

void	check_first(char *line, t_data *data)
{
	int	i;

	i = 0;
	(void)data;
	i = clear_whitespace(i, line) + 1;
	printf("%d\n", i);
}
