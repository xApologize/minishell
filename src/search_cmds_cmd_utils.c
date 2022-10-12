#include "../include/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/unistd.h>
#include <unistd.h>

char	*access_absolute_path(char *line)
{
	//gerer les erreur
	if (access(line, X_OK) == 0)
		return (ft_strdup(line));
	else
		dprintf(2, "minicougar: %s: no such file or directory\n", line);
	return (NULL);
}

char	*access_relative_path(char *line)
{
	char	*slash;
	char	*pwd_join;

	pwd_join = NULL;
	slash = ft_strjoin("/", line);
	pwd_join = ft_strjoinfree(getcwd(pwd_join, 0), slash);
	if (!pwd_join)
		return (ft_strdup(line));
	if (access(pwd_join, X_OK) == 0)
		return (pwd_join);
	dprintf(2, "minicougar: %s: no such file or directory\n", line);
	return (NULL);
}

char	*get_path(char *line_cp, t_data *data)
{
	int		i;
	char	*slash;
	char	*access_try;

	i = 0;
	if (!data->path_split)
		return (ft_strdup(line_cp));
	if (ft_strchr("./", *line_cp))
		return (access_absolute_path(line_cp));
	slash = ft_strjoin("/", line_cp);
	while (data->path_split[i] != NULL)
	{
		access_try = ft_strjoin(data->path_split[i], slash);
		if (access(access_try, X_OK) == 0)
		{
			free(slash);
			return (access_try);
		}
		i++;
		free(access_try);
	}
	free(slash);
	return (ft_strdup(line_cp));
}

int	get_argv_count(t_data *data)
{
	char	*line_cp;
	char	*indexmeta_cp;
	int		argv_count;

	line_cp = data->line;
	indexmeta_cp = data->indexmeta;
	argv_count = 1;
	while (*indexmeta_cp != '\0')
	{
		if (*line_cp == '\0' && ft_strchr("<>|\n", *indexmeta_cp))
			break ;
		if (*line_cp == '\0' && ft_strchr(" \n", *data->indexmeta))
		{
			while (*line_cp == '\0' && *indexmeta_cp == ' ')
			{
				line_cp++;
				indexmeta_cp++;
			}
			if (*line_cp != '\0')
				argv_count++;
		}
		line_cp++;
	}
	return (argv_count);
}

char	**get_argv(t_data *data)
{
	int		argv_count;
	int		i;
	char	**argv;

	argv_count = get_argv_count(data);
	argv = ft_calloc(sizeof(char*), argv_count + 1);
	i = 0;
	while (!ft_strchr("<>|\n", *data->indexmeta))
	{
		if (i == 0)
		{
			argv[i] = ft_strdup(data->line);
			i++;
		}
		if (*data->line == '\0' && ft_strchr(" \n", *data->indexmeta))
		{
			while (*data->line == '\0' && *data->indexmeta == ' ')
			{
				data->line++;
				data->indexmeta++;
			}
			if (*data->line != '\0')
				argv[i] = ft_strdup(data->line);
			i++;
		}
		else
			data->line++;
	}
	if (i == 0)
		argv[i] = ft_strdup(data->line);
	return (argv);
}
