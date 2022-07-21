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
	data->cmd_tab = (char **)ft_calloc(data->nb_tab + 1, sizeof(char *));
	data->l_t = 0;
	lines_lenght(line, data);

}

//meta_check pour split les meta dans le tableau sinon tout le reste fonctionne a date
void	lines_lenght(char *line, t_data *d)
{
	int		i;
	int		tab;

	i = 0;
	tab = 0;
	while (line[d->l_t] != '\0')
	{
		skip_ws(i, line, d);
		i = d->l_t;
		while (!ft_strchr(WS, line[d->l_t]) && \
		!ft_strchr(QUOTES, line[d->l_t]) && line[d->l_t])
			d->l_t++;
		if (ft_strchr(QUOTES, line[d->l_t]))
			i = skip_quotes(i, line, d);
		//meta_check(i, d, line);
		if (tab < d->nb_tab)
		{
			d->cmd_tab[tab] = ft_substr(line, i, d->l_t - i);
			printf("d->cmd_tab = %s\n", d->cmd_tab[tab]);
			tab++;
		}
		while (!ft_strchr(WS, line[d->l_t]))
			d->l_t++;
	}
}

void skip_ws(int i, char *line, t_data *data)
{
	while (ft_strchr(WS, line[data->l_t]) \
	&& !ft_strchr(QUOTES, line[data->l_t]))
	{
		i++;
		data->l_t++;
	}
}

int	skip_quotes(int i, char *line, t_data *data)
{
	//printf("l_t: %i et line: %s\n", data->l_t, line);
	if (line[data->l_t] == '\"')
	{
		while (!ft_strchr(WS_METACHAR, line[i - 1]) && i >= 0)
			i--;
		data->l_t++;
		while (line[data->l_t] != '\"')
			data->l_t++;
		while (!ft_strchr(WS, line[data->l_t + 1]))
			data->l_t++;
	}
	if (line[data->l_t] == '\'')
	{
		while (!ft_strchr(WS_METACHAR, line[i - 1]) && i >= 0)
			i--;
		data->l_t++;
		while (line[data->l_t] != '\'')
			data->l_t++;
		while (!ft_strchr(WS, line[data->l_t + 1]))
			data->l_t++;
	}
	data->l_t++;
	return (i);
}
