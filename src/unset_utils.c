#include "../include/minishell.h"

char	**handle_unset(t_cmd *cmd)
{
	int		i;
	bool	copy;

	i = 1;
	copy = false;
	while (cmd->argv[i])
	{
		if (!checkvalidarg(cmd->argv[i]))
			dprintf(STDERR_FILENO, "msh: unset: '%s': not a valid identifier\n", cmd->argv[i]);
		else
		{
			copy = true;
			modifyvar(cmd->argv[i], cmd->env);
		}
		i++;
	}
	if (!copy)
		return (cmd->env);
	else
		return (copynewenvp(cmd->env));
}

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
	free_the_pp(envp_copy);
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
