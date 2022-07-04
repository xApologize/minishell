#include "../include/minishell.h"

void	parsing(char *line, char **envp, t_data *data)
{
	access(envp[0], F_OK);
	split_line(line, data);
	search_cmd(data);
	env_split(data);
	//error_quotation(data);
}

void	split_line(char *line, t_data *data)
{
	data->line_split = ft_split(line, ' ');
}
