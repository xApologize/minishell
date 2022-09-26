#include "../include/minishell.h"

void	env_split(t_data *data, char **envp_copy)
{
	int		find;
	char	*tmp;

	find = 0;
	data->path_split = NULL;
	while (envp_copy[find])
	{
		if (ft_strncmp(envp_copy[find], "PATH=", 5) == 0)
			break ;
		find++;
	}
	if (envp_copy[find] != NULL)
		data->path_split = ft_split(envp_copy[find], ':');
	tmp = ft_strdup(data->path_split[0]);
	free(data->path_split[0]);
	data->path_split[0] = ft_substr(tmp, 5, ft_strlen(tmp) - 5);
	free(tmp);
}
