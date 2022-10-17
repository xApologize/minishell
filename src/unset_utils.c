#include "../include/minishell.h"

extern char	**g_envp_copy;

//finds and removes specified arg from environment variables if found 
void	handle_unset(t_cmd *cmd)
{
	int		i;
	bool	copy;

	i = 1;
	copy = false;
	while (cmd->argv[i])
	{
		if (!checkvalidarg(cmd->argv[i]))
		{
			dprintf(STDERR_FILENO, "minicougar: unset: \
			'%s': not a valid identifier\n", cmd->argv[i]);
			set_exit_code(1);
			return ;
		}
		else
		{
			copy = true;
			modifyvar(cmd->argv[i]);
		}
		i++;
	}
	set_exit_code(0);
	if (copy)
		copynewenvp();
}

//checks if var is part of the environment variables. returns true if found, false otherwise
bool	checkifunset(char *var, char *envp_var)
{
	char	**split_envp;

	split_envp = ft_split(envp_var, '=');
	if (ft_strcmp(var, split_envp[0]) == 0)
	{
		free_the_pp(split_envp);
		return (true);
	}
	free_the_pp(split_envp);
	return (false);
}

//creates new environment variables minus the ones that are removed
void	copynewenvp(void)
{
	int		i;
	int		j;
	char	**new_envp;

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

//gets number of variables to be copied
int	countnewvars(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_envp_copy[i])
	{
		if (ft_strcmp(g_envp_copy[i], "dncp!") != 0)
			j++;
		i++;
	}
	return (j);
}

//sets var to !dncp so it does not get copied over into the new environment variables
void	modifyvar(char *var)
{
	int	i;

	i = 0;
	while (g_envp_copy[i])
	{
		if (checkifunset(var, g_envp_copy[i]))
		{
			free(g_envp_copy[i]);
			g_envp_copy[i] = ft_strdup("dncp!");
		}
		i++;
	}
}
