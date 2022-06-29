#include "../include/minishell.h"

void	search_cmd(t_data *data)
{
	int		i;
	char	*cmd_join;
	int		j;
	char	*check_path;

	i = 0;
	j = 0;
	trim_path(data);
	while (data->line_split[i] != NULL)
	{
		cmd_join = ft_strjoin("/", data->line_split[i]);
		while (data->path_split[j] != NULL)
		{
			check_path = ft_strjoin(data->path_split[j], cmd_join);
			j++;
		}
		i++;
	}
}

void	env_split(t_data *data)
{
	data->path_split = ft_split(getenv("PATH="), ':');
}

void	trim_path(t_data *data)
{
	char	*tmp;

	tmp = ft_strdup(data->path_split[0]);
	data->path_split[0] = ft_substr(tmp, 5, ft_strlen(tmp));
	free(tmp);
}
