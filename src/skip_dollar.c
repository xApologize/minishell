#include "../include/minishell.h"

char	*skip_dollar(char *line)
{
	while (*line)
	{
		if (ft_strchr("<>|\t \n\"\0", *line))
			break ;
		line++;
	}
	return (line);
}
