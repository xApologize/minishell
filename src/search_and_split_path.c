#include "include/minishell.h"

void	search_split_path(char **envp, t_data *data)
{
	int	i;

	i = 0;
	while (!ft_strncmp(envp[i], "PATH=", 5))
		i++;
	data->path = envp[i];
	split_path(data);
}

void	split_path(t_data *data)
{
	data->path_split = ft_split(data->path, ':');
}