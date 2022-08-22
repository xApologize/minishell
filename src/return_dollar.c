#include "../include/minishell.h"

char	*return_dollar(char *line, char **envp_copy)
{
	char	*return_line;
	char	*var;
	char	**split_path;
	int		index;

	var = return_var(line);
	index = find_var(var, envp_copy);
	free(var);
	split_path = ft_split(envp_copy[index], '=');
	return_line = ft_strdup(split_path[1]);
	freeopt(split_path);
	return (return_line);
}