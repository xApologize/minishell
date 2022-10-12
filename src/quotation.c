#include "../include/minishell.h"

void	error_quotation(t_data *data)
{
	data->error_quotes = false;
	double_check(data);
	if (data->error_quotes == true)
		dprintf(STDERR_FILENO, "minicougar: odd number of quotes\n");
}


//if encounters single || double, set trigger to 1 and store character encountered. if character encountered again set trigger to 0.
//keep going until end of string
void	double_check(t_data *data)
{
	int	i;
	int	trigger;
	char c;
	
	i = 0;
	c = 0;
	trigger = 0;
	while (data->line[i])
	{
		if (data->line[i] == '\'' || data->line[i] == '"')
		{
			c = data->line[i];
			trigger = 1;
			i++;
			while (data->line[i])
			{
				if (data->line[i] == c)
				{
					trigger = 0;
					c = 0;
					break;
				}
				i++;
			}
		}
		i++;
	}
	if (trigger == 1)
		data->error_quotes = true;
}

void	single_check(t_data *data)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (data->line[i])
	{
		if (data->line[i] == '\'' && trigger == 0)
		{
			trigger = 1;
			i++;
			while (data->line[i] != '\'' && data->line[i])
				i++;
		}
		if (data->line[i] == '\'' && trigger == 1)
			trigger = 0;
		i++;
	}
	if (trigger == 1)
		data->error_quotes = true;
}
