#include "../include/minishell.h"

void	quote_on(bool *quote, int *i)
{
	*quote = true;
	*i += 1;
}

void	d_quote_on(bool *d_quote, int *i)
{
	*d_quote = true;
	*i += 1;
}

char	*met_quote(char *new_line, char **line, bool *d_quote)
{
	*d_quote = true;
	new_line = charjoinfree(new_line, **line);
	*line += 1;
	return (new_line);
}