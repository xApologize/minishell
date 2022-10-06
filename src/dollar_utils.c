#include "../include/minishell.h"

//checks if line contains a valid $ for unwrapping. if so unwrap dollar returns and replaces the value if found
char	*handle_dollar(char *line)
{
	char	*new_line;

	if (check_question(line))
	{
		new_line = unwrap_enigma(line);
		free(line);
		if (!check_dollar(new_line))
			return (new_line);
	}
	else if (check_dollar(line))
	{
		new_line = unwrap_dollar(line);
		free(line);
		return (new_line);
	}
	return (line);
}

//finds and replaces the $var if found within the environment variables
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

//copies the variables up until a token, newline, space or the end of the string is reached
char	*return_var(char *line)
{
	char	*var;

	var = ft_calloc(10, 1);
	line++;
	while (*line)
	{
		if (ft_isalnum(*line) == 0)
			break ;
		var = charjoinfree(var, *line);
		line++;
	}
	return (var);
}
//returns the index of the variable if found in the environment variables. returns -1 if not found
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
//copies one character at a time into a string
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
