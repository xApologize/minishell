#include "../include/minishell.h"

char	**addtoenv(char *arg, char **envp_copy)
{
	char	**new_envp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (envp_copy[i])
		i++;
	new_envp = malloc((i + 2) * sizeof(char *));
	while (envp_copy[++j])
		new_envp[j] = ft_strdup(envp_copy[j]);
	new_envp[i] = ft_strdup(arg);
	new_envp[i + 1] = NULL;
	freeopt(envp_copy);
	return (new_envp);
}

char	**modify_var(char *arg, char **envp_copy)
{
	int	index;

	index = find_var(arg, envp_copy);
	free(envp_copy[index]);
	envp_copy[index] = ft_strdup(arg);
	return (envp_copy);
}

int	check_dup_env(char *arg, char **envp_copy)
{
	int	i;

	i = -1;
	while (envp_copy[++i])
	{
		if (ft_strcmp(envp_copy[i], arg) == 0)
			return (1);
	}
	return (0);
}
