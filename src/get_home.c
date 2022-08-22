#include "../include/minishell.h"

char	*get_home(char **envp_copy)
{
	char	**split_envp;
	char	*rstring;
	int		i;

	i = 0;
	while (envp_copy[i])
	{
		split_envp = ft_split(envp_copy[i], '=');
		if (ft_strcmp(split_envp[0], "HOME") == 0)
		{
			rstring = ft_strdup(split_envp[1]);
			freeopt(split_envp);
			return (rstring);
		}
		freeopt(split_envp);
		i++;
	}
	return (NULL);
}