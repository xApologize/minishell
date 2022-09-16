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

	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		handle_echo(cmd->argv);
	else if (ft_strcmp(cmd->argv[0], "cd") == 0)
		handle_cd(cmd->argv, cmd->env);
	else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		handle_pwd(cmd->argv);
	else if (ft_strcmp(cmd->argv[0], "export") == 0)
		cmd->env = handle_export(cmd->argv, cmd->env);
	else if (ft_strcmp(cmd->argv[0], "unset") == 0)
		cmd->env = handle_unset(cmd->argv, cmd->env);
	else if (ft_strcmp(cmd->argv[0], "env") == 0)
		handle_env(cmd->argv, cmd->env);
	else if (ft_strcmp(cmd->argv[0], "exit") == 0)
		handle_exit(cmd, data);
	else if (ft_strcmp(cmd->argv[0], "pepe") == 0)
		pepe();
	return (cmd->env);
}