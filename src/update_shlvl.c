#include "../include/minishell.h"

static int	find_shlvl(void)
{
	char	**envp_split;
	int		i;

	i = -1;
	while (g_envp_copy[++i])
	{
		envp_split = ft_split(g_envp_copy[i], '=');
		if (ft_strcmp(envp_split[0], "SHLVL") == 0)
		{
			free_the_pp(envp_split);
			return (i);
		}
		free_the_pp(envp_split);
	}
	free_the_pp(envp_split);
	return (-1);
}

void	update_shlvl(void)
{
	int		index;
	int		level;
	char	*string_level;
	char	**shlvl_split;

	index = find_shlvl();
	if (index == -1)
		return ;
	else
	{
		shlvl_split = ft_split(g_envp_copy[index], '=');
		if (check_if_num(shlvl_split[1]) == true)
		{
			level = ft_atoi(shlvl_split[1]);
			level++;
			free(g_envp_copy[index]);
			g_envp_copy[index] = ft_strdup("SHLVL=");
			string_level = ft_itoa(level);
			g_envp_copy[index] = ft_strjoinfree(g_envp_copy[index], string_level);
			free(string_level);
		}
		else
			return ;
	}
}
