#include "../include/minishell.h"

bool	error_quotation(char *line)
{
	int	i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i++] == '\'')
		{
			while (line[i] != '\'')
			{
				i++;
				if (line[i] == '\0')
					return (true);
			}
		}
		if (line[i++] == '\"')
		{
			while (line[i] != '\"')
			{
				i++;
				if (line[i] == '\0')
					return (true);
			}
		}
	}
	return (false);
}
