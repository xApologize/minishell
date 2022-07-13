#include "../include/minishell.h"

void	parsing(char *line, char **envp_copy, t_data *data)
{
	sig_reset();
	access(envp_copy[0], F_OK);
	split_line(line, data);
	env_split(data, envp_copy);
	check_first(line, data);
	search_cmd(data);
	//error_quotation(data);
	sig_handling();
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
