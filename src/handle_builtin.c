#include "../include/minishell.h"

// ◦ echo et l’option -n
// ◦ cd uniquement avec un chemin relatif ou absolu
// ◦ pwd sans aucune option
// ◦ export sans aucune option
// ◦ unset sans aucune option
// ◦ env sans aucune option ni argument
// ◦ exit sans aucune option

// Need to finish handle_unset
char	**handle_builtin(t_cmd *cmd, char **envp_copy)
{

	if (ft_strcmp(cmd->argv[0], "echo\n") == 0)
		handle_echo(cmd->argv);
	else if (ft_strcmp(cmd->argv[0], "cd\n") == 0)
		handle_cd(cmd->argv, envp_copy);
	else if (ft_strcmp(cmd->argv[0], "pwd\n") == 0)
		handle_pwd(cmd->argv);
	else if (ft_strcmp(cmd->argv[0], "export\n") == 0)
		envp_copy = handle_export(cmd->argv, envp_copy);
	else if (ft_strcmp(cmd->argv[0], "unset\n") == 0)
		envp_copy = handle_unset(cmd->argv, envp_copy);
	else if (ft_strcmp(cmd->argv[0], "env\n") == 0)
		handle_env(cmd->argv, envp_copy);
	else if (ft_strcmp(cmd->argv[0], "exit\n") == 0)
		handle_exit(cmd->argv, envp_copy);
	return (envp_copy);
}