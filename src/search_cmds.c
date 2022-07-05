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
	access(check_path, F_OK);
}

void	env_split(t_data *data, char **envp_copy)
{
	int	find;

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
}

void	trim_path(t_data *data)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(data->path_split[0]);
	data->path_split[0] = ft_substr(tmp, 5, ft_strlen(tmp));
	free(tmp);
	while (data->path_split[i])
	{
		printf("path_split = %s\n", data->path_split[i]);
		i++;
	}
}
