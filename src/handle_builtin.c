#include "../include/minishell.h"

// ◦ echo et l’option -n
// ◦ cd uniquement avec un chemin relatif ou absolu
// ◦ pwd sans aucune option
// ◦ export sans aucune option
// ◦ unset sans aucune option
// ◦ env sans aucune option ni argument
// ◦ exit sans aucune option

void	handle_builtin(char *line, char **envp)
{
	char	**opt;

	opt = ft_split(line, ' ');
	if (ft_strncmp(opt[0], "echo", ft_strlen(opt[0])) == 0)
		handle_echo(opt);
	else if (ft_strncmp(opt[0], "cd", ft_strlen(opt[0])) == 0)
		handle_cd(opt);
	else if (ft_strncmp(opt[0], "pwd", ft_strlen(opt[0])) == 0)
		handle_pwd(opt);
	else if (ft_strncmp(opt[0], "export", ft_strlen(opt[0])) == 0)
		handle_export(opt);
	else if (ft_strncmp(opt[0], "unset", ft_strlen(opt[0])) == 0)
		handle_unset(opt);
	else if (ft_strncmp(opt[0], "env", ft_strlen(opt[0])) == 0)
		handle_env(opt, envp);
	else if (ft_strncmp(opt[0], "exit", ft_strlen(opt[0])) == 0)
		handle_exit(opt);
	else
		return ;
}