#include "../include/minishell.h"

// ◦ echo et l’option -n
// ◦ cd uniquement avec un chemin relatif ou absolu
// ◦ pwd sans aucune option
// ◦ export sans aucune option
// ◦ unset sans aucune option
// ◦ env sans aucune option ni argument
// ◦ exit sans aucune option

void	handle_builtin(char *line, char **envp_copy)
{
	char	**opt;

	if (ft_strlen(line) == 0)
		return ;
	opt = ft_split(line, ' ');
	if (ft_strcmp(opt[0], "echo") == 0)
		handle_echo(line, opt);
	else if (ft_strcmp(opt[0], "cd") == 0)
		handle_cd(opt);
	else if (ft_strcmp(opt[0], "pwd") == 0)
		handle_pwd(opt);
	else if (ft_strcmp(opt[0], "export") == 0)
		handle_export(opt, envp_copy);
	else if (ft_strcmp(opt[0], "unset") == 0)
		handle_unset(opt, envp_copy);
	else if (ft_strcmp(opt[0], "env") == 0)
		handle_env(opt, envp_copy);
	else if (ft_strcmp(opt[0], "exit") == 0)
		handle_exit();
	else
		return ;
}