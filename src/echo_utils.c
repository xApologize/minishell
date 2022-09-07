#include "../include/minishell.h"

void	handle_echo(char **opt)
{
	if (check_n(opt[1]) == 1)
		print_echo_with_n(line);
	else
		print_echo_without_n(line);
}

int	skip_echo(char *line)
{
	int i;

	i = 0;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	while (ft_isalnum(line[i]) == 1)
		i++;
	return (i);
}

int	skip_n(char *line)
{
	int	i;
	int	trigger;

	i = skip_echo(line);
	trigger = 0;
	while (line[i])
	{
		if (line[i] == '-')
			trigger = 1;
		if (trigger == 1 && (line[i] == ' ' || line[i] == '\t'))
			trigger = 0;
		if (trigger == 0 && ft_isalnum(line[i]) == 1)
			return (i); 
		if (trigger == 1 && ft_isalnum(line[i]) == 1 && line[i] != 'n')
		{
			while (line[i] != ' ' && line[i] != '\t')
				i--;
			return (i);
		}
	i++;
	}
	return (-1);
}

void	print_echo_with_n(char *line)
{
	int		i;
	int		j;
	char 	*str;
	char 	*pstr;

	i = skip_n(line);
	j = ft_strlen(line);
	str = ft_substr(line, i, (j - i));
	pstr = ft_strtrim(str, ' ');
	free(str);
	printf("%s", pstr);
	free(pstr);
}

void	print_echo_without_n(char *line)
{
	int		i;
	int		j;
	char	*str;
	char	*pstr;

	i = 0;
	j = ft_strlen(line);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (ft_isalpha(line[i]) == 1)
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	str = ft_substr(line, i, (j - i));
	pstr = ft_strtrim(str, ' ');
	free(str);
	printf("%s\n", pstr);
	free(pstr);
}
