#include "../include/minishell.h"

void	addtoenv(char *arg)
{
	char	**new_envp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (g_envp_copy[i])
		i++;
	new_envp = malloc((i + 2) * sizeof(char *));
	while (g_envp_copy[++j])
		new_envp[j] = ft_strdup(g_envp_copy[j]);
	new_envp[i] = ft_strdup(arg);
	new_envp[i + 1] = NULL;
	free_the_pp(g_envp_copy);
	g_envp_copy = new_envp;
}

void	modify_var(char *arg)
{
	int	index;

	index = find_var(arg);
	free(g_envp_copy[index]);
	g_envp_copy[index] = ft_strdup(arg);
}

int	check_dup_env(char *arg)
{
	int	i;

	i = -1;
	while (g_envp_copy[++i])
	{
		if (ft_strcmp(g_envp_copy[i], arg) == 0)
			return (1);
	}
	return (0);
}
