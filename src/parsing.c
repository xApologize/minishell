#include "../include/minishell.h"

void	parsing(char **envp_copy, t_data *data, t_cmd *cmd)
{
	error_quotation(data);
	tokenize(data);
	status(data);
	env_split(data, envp_copy);
	cmd = set_exec_struct(data, envp_copy);
	search_cmd(data, cmd);
}

void	tokenize(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->line_lenght = ft_strlen(data->line);
	findlenght(data);
	i = 0;
	while (data->line[i] != '\0')
	{
		if (ft_strchr(QUOTES, data->line[i]))
			i = quote(i, data);
		if (ft_strchr(WS_METACHAR, data->line[i]))
		{
			data->indexmeta[j] = data->line[i];
			data->line[i] = '\0';
			j++;
		}
		i++;
	}
}

int	quote(int i, t_data *data)
{
	if (ft_strchr("\'", data->line[i]))
	{
		i++;
		while (!ft_strchr("\'", data->line[i]))
		{
			i++;
		}
	}
	if (ft_strchr("\"", data->line[i]))
	{
		i++;
		while (!ft_strchr("\"", data->line[i]))
		{
			i++;
		}
	}
	i++;
	return (i);
}

void	findlenght(t_data *data)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = 0;
	while (data->line[i] != '\0')
	{
		if (ft_strchr(QUOTES, data->line[i]) && data->line[i])
			i = quote(i, data);
		if (ft_strchr(WS_METACHAR, data->line[i]) && data->line[i])
			lenght++;
		i++;
	}
	data->indexmeta = ft_calloc(lenght + 1, sizeof (char));
}

