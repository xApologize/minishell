#include "../include/minishell.h"

void	parsing(char *line, char **envp, t_data *data)
{
	envp = NULL;
	split_line(line, data);
	search_cmd(data);
	env_split(data);
	//error_quotation(data);
}

void	split_line(char *line, t_data *data)
{
	data->line_split = ft_split(line, ' ');
}
