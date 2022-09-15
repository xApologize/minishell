#include "../include/minishell.h"

// handle echo done
// handle_cd done
// handle_pwd
// handle_export done
// handle_unset done
// handle_env done
// 

char	**handle_builtin(t_cmd *cmd, t_data *data)
{

	if (ft_strcmp(cmd->argv[0], "echo\n") == 0)
		handle_echo(cmd->argv);
	else if (ft_strcmp(cmd->argv[0], "cd\n") == 0)
		handle_cd(cmd->argv, cmd->env);
	else if (ft_strcmp(cmd->argv[0], "pwd\n") == 0)
		handle_pwd(cmd->argv);
	else if (ft_strcmp(cmd->argv[0], "export\n") == 0)
		cmd->env = handle_export(cmd->argv, cmd->env);
	else if (ft_strcmp(cmd->argv[0], "unset\n") == 0)
		cmd->env = handle_unset(cmd->argv, cmd->env);
	else if (ft_strcmp(cmd->argv[0], "env\n") == 0)
		handle_env(cmd->argv, cmd->env);
	else if (ft_strcmp(cmd->argv[0], "exit\n") == 0)
		handle_exit(cmd, data);
	else if (ft_strcmp(cmd->argv[0], "pepe\n") == 0)
		pepe();
	return (cmd->env);
}