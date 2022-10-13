#include "../include/minishell.h"

int	get_mem_len(char *arg, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (arg[++i])
	{
		if (arg[i] != c)
			count++;
	}
	return (count);
}

char	*stripstring(char *arg)
{
	char	*new_string;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (arg[0] == '\'' || arg[0] == '"')
	{
		new_string = ft_calloc((get_mem_len(arg, arg[0]) + 1), sizeof (char));
		while (arg[++i])
		{
			if (arg[i] != arg[0])
			{
				new_string[j] = arg[i];
				j++;
			}
		}
		new_string[j] = '\0';
		free(arg);
		return (new_string);
	}
	return (arg);
}

char	*skip_single_quote(char *line)
{
	line++;
	while (*line != '\'' && *line)
		line++;
	return (line);
}