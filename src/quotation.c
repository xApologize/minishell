#include "../include/minishell.h"

void	error_quotation(t_data *data)
{
	data->error_quotes = false;
	double_check(data);
	if (data->error_quotes == false)
		single_check(data);
	if (data->error_quotes == true)
		dprintf(STDERR_FILENO, "minicougar: odd number of quotes\n");
}

void	double_check(t_data *data)
{
	int i;
	int trigger;

	i = -1;
	trigger = 0;
	while (data->line[++i])
	{
		if (data->line[i] == '"' && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		if (data->line[i] == '"' && trigger == 1)
			trigger = 0;
	}
	if (trigger == 1)
		data->error_quotes = true;
}

void	single_check(t_data *data)
{
	int i;
	int trigger;

	i = -1;
	trigger = 0;
	while (data->line[++i])
	{
		if (data->line[i] == '\'' && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		if (data->line[i] == '\'' && trigger == 1)
			trigger = 0;
	}
	if (trigger == 1)
		data->error_quotes = true;
}