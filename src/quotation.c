#include "../include/minishell.h"

bool	error_quotation(t_data *data)
{
	int	i;

	data->error_quotes = false;
	i = 0;
	while (data->line[i] != '\0')
	{
		if (data->line[i] == '\'')
		{
			i++;
			i = squotes(i, data);
		}
		if (data->line[i] == '\"')
		{
			i++;
			i = dquotes(i, data);
		}
		i++;
	}
	return (false);
}

int	squotes(int i, t_data *data)
{
	while (data->line[i] != '\'')
	{
		if (data->line[i] == '\0')
			data->error_quotes = true;
		i++;
	}
	return (i);
}

int	dquotes(int i, t_data *data)
{
	while (data->line[i] != '\"')
	{
		if (data->line[i] == '\0')
			data->error_quotes = true;
		i++;
	}
	return (i);
}
