#include "../include/minishell.h"

int	check_modify_env(char *arg, char **envp_copy)
{
	int		i;
	char	**split_arg;
	char	**split_envp_copy;

	i = -1;
	split_arg = ft_split(arg, '=');
	while (envp_copy[++i])
	{
		split_envp_copy = ft_split(envp_copy[i], '=');
		printf("%s\n", split_envp_copy[0]);
		printf("%s\n", split_arg[0]);
		if (ft_strcmp(split_arg[0], split_envp_copy[0]) == 0)
		{
			freeopt(split_arg);
			freeopt(split_envp_copy);
			printf("Returning 1\n");
			return (1);
		}
		freeopt(split_envp_copy);
	}
	freeopt(split_arg);
	printf("Returning 0\n");
	return (0);
}