#include "../include/minishell.h"

char	*charjoinfree(const char *s1, const char c)
{
	char	*newstring;
	int		len;

	len = ft_strlen(s1);
	newstring = malloc((len + 2) * sizeof(char));
	ft_strlcpy(newstring, s1, len + 1);
	newstring[len] = c;
	newstring[len + 1] = '\0';
	free((void *) s1);
	return (newstring);
}