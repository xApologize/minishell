#include "../include/minishell.h"

int	get_redir(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->indexmeta[i])
	{
		if (ft_strchr("<>", data->indexmeta[i]))
		{
			if (data->indexmeta[i] == '>' && data->indexmeta[i + 1] == '>')
			{
				i++;
				j++;
			}
			else
				j++;
		}
		i++;
	}
	return (j);
}

void file_redir(char *line, t_data *data)
{
	int		i;
	int		j;
	char	**redir;

	i = 0;
	j = 0;
	if (get_redir(data) > 0)
		redir = ft_calloc(sizeof(char*), get_redir(data));
	while (i < data->line_lenght)
	{
		if (line[i] == '\0')
		{
			if (data->indexmeta[j] == '>' || data->indexmeta[j] == '<')
			{
			}
		}
	}
}
