#include "../include/minishell.h"

void	parsing(char *line, t_data *data, t_cmd *cmd, char **environ)
{
	split_line(line, data);
	env_split(data, environ);
	search_cmd(data);
	//error_quotation(data);
}

void	split_line(char *line, t_data *data)
{
	data->line_split = ft_split(line, ' ');
}
