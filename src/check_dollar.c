#include "../include/minishell.h"

//single_quote prevents dollar from unwraping value

bool	check_dollar(char *line)
{
	int		i;
	bool	quote;

	i = -1;
	quote = false;
	while (line[++i])
	{
		if (line[i] == '\'')
		{
			quote = true;
			i++;
		}
		if (line[i] == '$' && ft_isalnum(line[i + 1]) == 1 && quote == false)
			return (true);
		if (line[i] == '\'' && quote == true)
			quote = false;
	}
	return (false);
}