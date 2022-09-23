#include "../include/minishell.h"

char	*charjoinfree(const char *s1, const char c)
{
	char	*newstring;
	int		len;

	len = ft_strlen(s1);
	printf("len: %d\n", len);
	newstring = ft_calloc(len + 2, sizeof(char));
	len = 0;
	while (s1[len])
	{
		write(1, &s1[len], 1);
		newstring[len] = s1[len];
		len++;
	}
	newstring[len] = c;
	newstring[len + 1] = '\0';
	free((void *) s1);
	s1 = NULL;
	return (newstring);
}