#include "../include/minishell.h"

void	parsing(char *line, char **envp, t_data *data)
{
	split_line(line, data);
	search_cmd(data);
	error_quotation(data);
}

void	split_line(char *line, t_data *data)
{
	data->line_split = ft_split(line, ' ');
}

void	search_cmd(t_data *data)
{
	int	i;

	i = 0;
	if ()
	{
		/* code */
	}
	
}