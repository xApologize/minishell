#include "../include/minishell.h"

bool	error_quotation(char *line, t_data *data)
{
	int	i;

	data->error_quotes = false;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\'')
		{
			i++;
			i = squotes(line, i, data);
		}
		if (line[i] == '\"')
		{
			i++;
			i = dquotes(line, i, data);
		}
		i++;
	}
	return (false);
}

int	squotes(char *line, int i, t_data *data)
{
	while (line[i] != '\'')
	{
		if (line[i] == '\0')
			data->error_quotes = true;
		i++;
	}
	return (i);
}

int	dquotes(char *line, int i, t_data *data)
{
	while (line[i] != '\"')
	{
		if (line[i] == '\0')
			data->error_quotes = true;
		i++;
	}
	return (i);
}
