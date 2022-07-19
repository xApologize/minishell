#include "../include/minishell.h"

int	find_nb_tb(char *line)
{
	int	i;
	int	nb_squotes;
	int	nb_dquotes;
	int	nb_tab;

	i = 0;
	nb_squotes = 0;
	nb_dquotes = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\'')
			nb_squotes++;
		if (line[i] == '\"')
			nb_dquotes++;
		i++;
	}
	if (nb_dquotes % 2 != 0 || nb_squotes % 2 != 0)
	{
		dprintf(2, "error odd quotes");
		//quit();
	}
	nb_tab = nb_tabs(line);
	printf("nb_tab = %d\n", nb_tab);
	return (nb_tab);
}

int	nb_tabs(char *line)
{
	int	i;
	int	nb_tab;

	i = 0;
	nb_tab = 0;
	nb_tab = nb_tabs_next(line, nb_tab, i);
	return (nb_tab);
}

int	nb_tabs_next(char *line, int nb_tab, int i)
{
	while (line[i] != '\0')
	{
		if (line[i] == '\'')
		{
			i++;
			while (line[i] != '\'')
				i++;
		}
		if (line[i] == '\"')
		{
			i++;
			while (line[i] != '\"')
				i++;
		}
		if (ft_strchr(WS_METACHAR, line[i]) && !ft_strchr(WS, line[i + 1]))
			nb_tab++;
		i++;
	}
	if (ft_strlen(line) != 0)
		nb_tab++;
	return (nb_tab);
}

