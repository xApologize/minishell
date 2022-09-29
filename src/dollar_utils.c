#include "../include/minishell.h"

char	*handle_dollar(char *line)
{
	char	*new_line;

	if (check_dollar(line))
	{
		new_line = unwrap_dollar(line);
		return (new_line);
	}
	return (line);
}

char	*return_dollar(char *line)
{
	char	*return_line;
	char	*var;
	char	**split_path;
	int		index;

	var = return_var(line);
	index = find_var(var);
	split_path = NULL;
	free(var);
	var = NULL;
	if (index != -1)
	{
		split_path = ft_split(g_envp_copy[index], '=');
		return_line = ft_strdup(split_path[1]);
		free_the_pp(split_path);
	}
	else
		return_line = (ft_strdup(""));
	return (return_line);
}

char	*return_var(char *line)
{
	char	*var;

	var = ft_calloc(10, 1);
	line++;
	while (*line)
	{
		if (ft_strchr("<>|\t \n\"", *line))
			break ;
		var = charjoinfree(var, *line);
		line++;
	}
	return (var);
}

int	find_var(char *arg)
{
	int		index;
	char	**arg_split;
	char	**envp_split;

	index = -1;
	arg_split = ft_split(arg, '=');
	while (g_envp_copy[++index])
	{
		envp_split = ft_split(g_envp_copy[index], '=');
		if (ft_strcmp(arg_split[0], envp_split[0]) == 0)
		{
			free_the_pp(arg_split);
			free_the_pp(envp_split);
			return (index);
		}
		free_the_pp(envp_split);
	}
	free_the_pp(arg_split);
	return (-1);
}

char	*charjoinfree(const char *s1, const char c)
{
	char	*newstring;
	int		len;

	len = ft_strlen(s1);
	newstring = ft_calloc(len + 2, sizeof(char));
	len = 0;
	while (s1[len])
	{
		newstring[len] = s1[len];
		len++;
	}
	newstring[len] = c;
	newstring[len + 1] = '\0';
	free((void *) s1);
	s1 = NULL;
	return (newstring);
}
