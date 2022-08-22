#include "../include/minishell.h"

char	*skip_dollar(char *line)
{
	while (*line)
	{
		if (ft_strchr("<>|\t ", *line))
			break ;
		line++;
	}
	return (line);
}