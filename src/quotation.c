#include "../include/minishell.h"

bool	error_quotation(void)
{
	int	i;

	_data.error_quotes = false;
	i = 0;
	while (_data.line[i] != '\0')
	{
		if (_data.line[i] == '\'')
		{
			i++;
			i = squotes(i);
		}
		if (_data.line[i] == '\"')
		{
			i++;
			i = dquotes(i);
		}
		i++;
	}
	return (false);
}

int	squotes(int i)
{
	while (_data.line[i] != '\'')
	{
		if (_data.line[i] == '\0')
			_data.error_quotes = true;
		i++;
	}
	return (i);
}

int	dquotes(int i)
{
	while (_data.line[i] != '\"')
	{
		if (_data.line[i] == '\0')
			_data.error_quotes = true;
		i++;
	}
	return (i);
}
