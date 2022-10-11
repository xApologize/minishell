#include "../include/minishell.h"

static void	find_shlvl(void)
{
	char	**envp_split;
	int		i;

	i = -1;
	while (g_envp_copy[++i])
	{
		envp_split = ft_split(g_envp_copy[i], '=');
		if (ft_strcmp(envp_split[0], "SHLVL") == 0)
		{
			free(g_envp_copy[i]);
			g_envp_copy[i] = ft_strdup("dncp!");
		}
	}
}

void	remove_shlvl(void)
{
	int		i;
	int		j;
	char	**new_envp;

	find_shlvl();
	i = countnewvars();
	j = 0;
	new_envp = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (g_envp_copy[i])
	{
		if (ft_strcmp(g_envp_copy[i], "dncp!") != 0)
		{
			new_envp[j] = ft_strdup(g_envp_copy[i]);
			j++;
		}
		i++;
	}
	new_envp[j] = NULL;
	free_the_pp(g_envp_copy);
	g_envp_copy = new_envp;
}
