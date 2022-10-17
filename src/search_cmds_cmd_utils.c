#include "../include/minishell.h"

extern char	**g_envp_copy;

char	*access_absolute_path(char *line)
{
	//gerer les erreur
	if (access(line, X_OK) == 0)
	{
		free(line);
		return (ft_strdup(line));
	}
	else
		dprintf(2, "minicougar: %s: no such file or directory\n", line);
	free(line);
	return (NULL);
}

char	*access_relative_path(char *line)
{
	char	*slash;
	char	*pwd_join;

	//gerer les erreur
	slash = ft_strjoin("/", line);
	pwd_join = ft_strjoin(getenv("PWD"), slash);
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
	line_cp = handle_dollar(line_cp);
	line_cp = stripstring(line_cp);
	if (!data->path_split)
		return (line_cp);
	if (ft_strchr("./", *line_cp))
		return (access_absolute_path(line_cp));
	slash = ft_strjoin("/", line_cp);
	while (data->path_split[i] != NULL)
	{
		access_try = ft_strjoin(data->path_split[i], slash);
		if (access(access_try, X_OK) == 0)
		{
			free(line_cp);
			free(slash);
			return (access_try);
		}
		i++;
		free(access_try);
	}
	free(slash);
	return (line_cp);
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
//quote stripping before the expansion. expansion after the heredoc
char	**get_argv(t_data *data)
{
	int		argv_count;
	int		i;
	char	**argv;

	argv_count = get_argv_count(data);
	argv = ft_calloc(sizeof(char*), (argv_count + 1));
	i = 0;
	while (!ft_strchr("<>|\n", *data->indexmeta))
	{
		if (i == 0)
		{
			argv[i] = handle_dollar(ft_strdup(data->line));
			argv[i] = stripstring(argv[i]);
			i++;
		}
		if (*data->line == '\0' && ft_strchr(" \n", *data->indexmeta))
		{
			while (*data->line == '\0' && *data->indexmeta == ' ')
				skip_char(data);
			if (*data->line != '\0')
			{
				argv[i] = handle_dollar(ft_strdup(data->line));
				argv[i] = stripstring(argv[i]);
			}
			i++;
		}
		else
			data->line++;
	}
	if (i == 0)
		argv[i] = ft_strdup(data->line);
	return (argv);
}
