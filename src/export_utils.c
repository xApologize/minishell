#include "../include/minishell.h"
extern char **g_envp_copy;

void	handle_export(t_cmd *cmd)
{
	int		i;
	bool	valid_env;
	bool	valid_assign;

	i = 0;
	if (!cmd->argv[1])
	{
		handle_env(cmd);
		return ;
	}
	while (cmd->argv[++i])
	{
		valid_env = checkvalidenv(cmd->argv[i]);
		valid_assign = checkvalidassign(valid_env, cmd->argv[i]);
		if (valid_assign == true && check_modify_env(cmd->argv[i]) == 1)
		{
			modify_var(cmd->argv[i]);
			set_exit_code(0);
		}
		if (valid_assign == true && check_dup_env(cmd->argv[i]) == 0)
		{
			addtoenv(cmd->argv[i]);
			set_exit_code(0);
		}
	}
}

bool	checkvalidenv(char *arg)
{
	int	i;

	i = 0;
	if (ft_isalpha(arg[0]) == 0 && arg[0] != '_')
		return (false);
	while (arg[i] != '=' && arg[i] != '\0')
	{
		if (ft_isalnum(arg[i]) == 0 && arg[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

bool	checkvalidassign(bool env_stat, char *arg)
{
	bool	is_valid;

	is_valid = checkassign(arg);
	if (!env_stat)
	{
		dprintf(STDERR_FILENO, \
		"export: '%s': not a valid identifier\n", arg);
		set_exit_code(1);
		return (false);
	}
	else if (!is_valid)
		return (false);
	return (true);
}

int	check_modify_env(char *arg)
{
	int		i;
	char	**split_arg;
	char	**split_envp_copy;

	i = -1;
	split_arg = ft_split(arg, '=');
	while (g_envp_copy[++i])
	{
		split_envp_copy = ft_split(g_envp_copy[i], '=');
		if (ft_strcmp(split_arg[0], split_envp_copy[0]) == 0)
		{
			free_the_pp(split_arg);
			free_the_pp(split_envp_copy);
			return (1);
		}
		free_the_pp(split_envp_copy);
	}
	free_the_pp(split_arg);
	return (0);
}
