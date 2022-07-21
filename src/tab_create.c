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
	if (ft_strlen(line) != 0)
		nb_tab++;
	while (ft_strchr(WS, line[i]))
		i++;
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
		printf("i = %d\n", i);
		i = check_meta(line, i, &nb_tab);
		if (ft_strchr(WS, line[i]) && !ft_strchr(WS, line[i + 1]))
			nb_tab++;
		i++;
	}
	return (nb_tab);
}

//check pour | "|" | sa donne un tab de trop pour trouver la hauteur du tableau
int	check_meta(char *line, int i, int *nb_tabs)
{
	if (ft_strchr(METACHAR, line[i]))
	{
		i++;
		nb_tabs++;
		if (line[i] == '\0')
			return (i);
		if (ft_strchr(METACHAR, line[i]))
		{
			printf("i 2 = %d\n", i);
			i++;
		}
		if (ft_strchr(WS, line[i]))
		{
			DEBUG;
			*nb_tabs += 1;
		}
		else
			*nb_tabs += 2;
		if (line[i + 1] == '\0')
			i++;
	}
	return (i);
}

// int	meta_check(int i, t_data *d, char *line)
// {
	
// 	return (i);
// }