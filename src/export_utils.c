#include "../include/minishell.h"

char	**handle_export(t_cmd *cmd)
{
	int	i;
	bool	valid_env;
	bool	valid_assign;

	i = 0;
	while (cmd->argv[++i])
	{
		valid_env = checkvalidenv(cmd->argv[i]);
		valid_assign = checkvalidassign(valid_env, cmd->argv[i]);
		if (valid_assign == true && check_modify_env(cmd->argv[i], cmd->env) == 1)
			cmd->env = modify_var(cmd->argv[i], cmd->env);
		if (valid_assign == true && check_dup_env(cmd->argv[i], cmd->env) == 0)
			cmd->env = addtoenv(cmd->argv[i], cmd->env);
	}
	return (cmd->env);
}

bool	checkvalidenv(char *arg)
{
	int	i;

	i = 0;
	if (ft_isalpha(arg[0]) == 0)
		return (false);
	while (arg[i] != '=' && arg[i] != '\0')
	{
		if (ft_isalnum(arg[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

bool	checkvalidassign(bool env_stat, char *arg)
{
	bool is_valid;

	is_valid = checkassign(arg);
	if (!env_stat)
	{
		dprintf(STDERR_FILENO, "msh: export: '%s': not a valid identifier\n", arg);
		return (false);
	}
	else if (!is_valid)
		return (false);
	return (true);
}

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
		if (ft_strcmp(split_arg[0], split_envp_copy[0]) == 0)
		{
			freeopt(split_arg);
			freeopt(split_envp_copy);
			return (1);
		}
		freeopt(split_envp_copy);
	}
	freeopt(split_arg);
	return (0);
}
