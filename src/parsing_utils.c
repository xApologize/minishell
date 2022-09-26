#include "../include/minishell.h"

void	env_split(t_data *data)
{
	int		find;
	char	*tmp;

	find = 0;
	data->path_split = NULL;
	while (g_envp_copy[find])
	{
		if (ft_strncmp(g_envp_copy[find], "PATH=", 5) == 0)
			break ;
		find++;
	}
	if (g_envp_copy[find] != NULL)
		data->path_split = ft_split(g_envp_copy[find], ':');
	tmp = ft_strdup(data->path_split[0]);
	free(data->path_split[0]);
	data->path_split[0] = ft_substr(tmp, 5, ft_strlen(tmp) - 5);
	free(tmp);
}
