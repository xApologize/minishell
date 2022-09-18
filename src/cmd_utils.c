#include "../include/minishell.h"
#include <stdio.h>
#include <stdlib.h>

char	*access_path(char *line)
{
	if (access(line, X_OK) == 0)
		return (line);
	// free(line);
	return (NULL);
}

char	*access_relative_path(char *line)
{
	char	*slash;
	char	*pwd_join;

	slash = ft_strjoin("/", line);
	pwd_join = ft_strjoin(getenv("PWD"), slash);
	if (access_path(pwd_join) != NULL)
	{
		// free(slash);
		return (pwd_join);
	}
	// free(slash);
	// free(pwd_join);
	return (NULL);
}



char	*get_path(char *line_cp)
{
	int		i;
	char	*slash;
	char	*access_try;

	i = 0;
	if (*line_cp == '/')
		return access_path(line_cp);
	if (*line_cp == '.')
		return (access_relative_path(line_cp));
	slash = ft_strjoin("/", line_cp);
	while (_data.path_split[i] != NULL)
	{
		access_try = ft_strjoin(_data.path_split[i], slash);
		if (access_path(access_try) != NULL)
		{
			free(slash);
			return (access_try);
		}
		i++;
		free(access_try);
	}
	free(slash);
	return (NULL);
}

int	get_argv_count(void)
{
	char	*line_cp;
	char	*indexmeta_cp;
	int		argv_count;

	line_cp = _data.line;
	indexmeta_cp = _data.indexmeta;
	argv_count = 1;
	while (*indexmeta_cp != '\0')
	{
		if (*line_cp == '\0' && ft_strchr("<>|\n", *indexmeta_cp))
			break ;
		if (*line_cp == '\0' && ft_strchr(" \n", *_data.indexmeta))
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

char	**get_argv(void)
{
	int		argv_count;
	int		i;
	char	**argv;

	argv_count = get_argv_count();
	argv = ft_calloc(sizeof(char*),  argv_count + 1);
	i = 0;
	while (!ft_strchr("<>|\n", *_data.indexmeta))
	{
		if (i == 0)
		{
			argv[i] = ft_strdup(_data.line);
			i++;
		}
		if (*_data.line == '\0' && ft_strchr(" \n", *_data.indexmeta))
		{
			while (*_data.line == '\0' && *_data.indexmeta == ' ')
			{
				_data.line++;
				_data.indexmeta++;
			}
			if (*_data.line != '\0')
				argv[i] = ft_strdup(_data.line);
			i++;
		}
		else 
			_data.line++;
	}
	if (i == 0)
		argv[i] = ft_strdup(_data.line);
	return (argv);
}
