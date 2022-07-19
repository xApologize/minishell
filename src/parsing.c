#include "../include/minishell.h"

void	parsing(char *line, char **envp_copy, t_data *data)
{
	sig_reset();
	access(envp_copy[0], F_OK);
	find_cmds(line, data);
	env_split(data, envp_copy);
	search_cmd(data);
	//error_quotation(data);
	sig_handling();
}

void	find_cmds(char *line, t_data *data)
{
	int	i;
	int	quotes;
	int	cmd_lenght;

	i = 0;
	quotes = 0;
	cmd_lenght = 0;
	data->nb_tab = find_nb_tb(line);
	data->cmd_tab = (char **)malloc(data->nb_tab + 1 * sizeof(char *));
	data->l_t = 0;
	printf("nb_tab = %d\n", data->nb_tab);
	lines_lenght(line, data);
}

void	lines_lenght(char *line, t_data *d)
{
	int		i;
	//char	*str;
	int		tab;

	i = 0;
	tab = 0;
	while (line[d->l_t] != '\0')
	{
		skip_ws(i, line, d);
		i = d->l_t;
		printf("line[i], line[l_t] : %c->%c\n", line[i], line[d->l_t]);
		skip_quotes(line, d);
		while (!ft_strchr(WS, line[d->l_t]))
			d->l_t++;
		// if (ft_strchr(WS, line[d->l_t]) && !ft_strchr(WS, line[d->l_t + 1]))
		d->cmd_tab[tab] = ft_substr(line, i, d->l_t - i);
		//printf("str = %s\n", str);
		printf("tab = %d\n", tab);
		printf("d->cmd_tab = %s\n", d->cmd_tab[tab]);
		// if (tab < d->nb_tab)
		// {
		// 	d->cmd_tab[tab] = str;
		// 	tab++;
		// }
	}
}


int skip_ws(int i, char *line, t_data *data)
{
	while (ft_strchr(WS, line[data->l_t]))
	{
		i++;
		data->l_t++;
	}
	return (i);
}

void	skip_quotes(char *line, t_data *data)
{
	if (line[data->l_t] == '\'')
	{
		data->l_t++;
		while (line[data->l_t] != '\'')
			data->l_t++;
	}
	if (line[data->l_t] == '\"')
	{
		data->l_t++;
		while (line[data->l_t] != '\"')
			data->l_t++;
	}
	data->l_t++;
}