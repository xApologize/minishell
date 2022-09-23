#include "../include/minishell.h"

char	*return_dollar(char *line, char **envp_copy)
{
	char	*return_line;
	char	*var;
	char	**split_path;
	int		index;

	var = return_var(line);
	index = find_var(var, envp_copy);
	// var and index are ok
	split_path = NULL;
	free(var);
	var = NULL;
	if (index != -1)
	{
		split_path = ft_split(envp_copy[index], '=');
		return_line = ft_strdup(split_path[1]);
		free_the_pp(split_path);
	}
	else
		return_line = (ft_strdup(""));
	return (return_line);
}

