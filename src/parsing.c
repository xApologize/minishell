#include "../include/minishell.h"

void	parsing(char *line, t_data *data, t_cmd *cmd, char **environ)
{
	split_line(line, data);
	env_split(data, environ);
	check_first(line, data);
	search_cmd(data, cmd);
	//error_quotation(data);
}

void	split_line(char *line, t_data *data)
{
	int	i;

	i = 0;
	data->line_split = ft_split(line, '|');
	while (data->line_split[i])
	{
		printf("line_split = %s\n", data->line_split[i]);
		i++;
	}
}

void	check_first(char *line, t_data *data)
{
	int	i;

	i = 0;
	(void)data;
	i = clear_whitespace(i, line) + 1;
	printf("%d\n", i);
}
