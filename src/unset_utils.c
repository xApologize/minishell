#include "../include/minishell.h"

char	**handle_unset(char **opt, char **envp_copy)
{
	int		i;
	bool	copy;

	i = 1;
	copy = false;
	while (opt[i])
	{
		if (!checkvalidarg(opt[i]))
			dprintf(STDERR_FILENO, \
			"msh: unset: '%s': not a valid identifier\n", opt[i]);
		else
		{
			copy = true;
			modifyvar(opt[i], envp_copy);
		}
		i++;
	}
	if (!copy)
		return (envp_copy);
	else
		return (copynewenvp(envp_copy));
}

bool	checkifunset(char *var, char *envp_var)
{
	char	**split_envp;

	split_envp = ft_split(envp_var, '=');
	if (ft_strcmp(var, split_envp[0]) == 0)
	{
		freeopt(split_envp);
		return (true);
	}
	freeopt(split_envp);
	return (false);
}

char	**copynewenvp(char **envp_copy)
{
	int		i;
	int		j;
	char	**new_envp;

	i = countnewvars(envp_copy);
	j = 0;
	new_envp = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (envp_copy[i])
	{
		if (ft_strcmp(envp_copy[i], "dncp!") != 0)
		{
			new_envp[j] = ft_strdup(envp_copy[i]);
			j++;
		}
		i++;
	}
	new_envp[j] = NULL;
	freeopt(envp_copy);
	return (new_envp);
}

int	countnewvars(char **envp_copy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp_copy[i])
	{
		if (ft_strcmp(envp_copy[i], "dncp!") != 0)
			j++;
		i++;
	}
	return (j);
}

void	modifyvar(char *var, char **envp_copy)
{
	int	i;

	i = 0;
	while (envp_copy[i])
	{
		if (checkifunset(var, envp_copy[i]))
		{
			free(envp_copy[i]);
			envp_copy[i] = ft_strdup("dncp!");
		}
		i++;
	}
}
