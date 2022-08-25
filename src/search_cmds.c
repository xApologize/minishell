#include "../include/minishell.h"

void	search_cmd(t_data *data, char *line)
{
	int		i;
	char	*cmd_join;
	int		j;
	int		check;
	char	*check_path;
	int		k;

	i = 0;
	j = 0;
	check = 0;
	k = 0;
	printf("line lenght = %d\n", data->line_lenght);
	while (i < data->line_lenght)
	{
		DEBUG;
		while (line[i] != '\0')
			i++;
		cmd_join = ft_strjoin("/", line);
		while (!ft_strchr("<>|", data->indexmeta[j]) && line[i] == '\0')
		{
			j++;
			i++;
			if (ft_strchr("<>|", data->indexmeta[j]))
				check = 1;
		}
		if (check == 1)
			break;
		while (data->path_split[k] != NULL)
		{
			check_path = ft_strjoin(data->path_split[k], cmd_join);
			printf("check_path = %s\n", check_path);
			if (access(check_path, X_OK) == 0)
				break;
			else
				k++;
		}
	}
	// while (data->line_split[i] != NULL)
	// {
	// 	cmd_join = ft_strjoin("/", data->line_split[i]);
	// 	while (data->path_split[j] != NULL)
	// 	{
	// 		check_path = ft_strjoin(data->path_split[j], cmd_join);
	// 		printf("check_path = %s\n", check_path);
	// 		j++;
	// 	}
	// 	i++;
	// 	(void) check_path;
	// }
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
		i++;
}
