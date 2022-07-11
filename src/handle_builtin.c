/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:29:32 by jrossign          #+#    #+#             */
/*   Updated: 2022/07/11 15:33:59 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// ◦ echo et l’option -n
// ◦ cd uniquement avec un chemin relatif ou absolu
// ◦ pwd sans aucune option
// ◦ export sans aucune option
// ◦ unset sans aucune option
// ◦ env sans aucune option ni argument
// ◦ exit sans aucune option

// Need to finish handle_unset && handle_export

char	**handle_builtin(char *line, char **envp_copy)
{
	char	**opt;

	if (ft_strlen(line) == 0)
		return (envp_copy);
	opt = ft_split(line, ' ');
	if (ft_strcmp(opt[0], "echo") == 0)
		handle_echo(line, opt);
	else if (ft_strcmp(opt[0], "cd") == 0)
		handle_cd(opt);
	else if (ft_strcmp(opt[0], "pwd") == 0)
		handle_pwd(opt);
	else if (ft_strcmp(opt[0], "export") == 0)
	{
		envp_copy = handle_export(opt, envp_copy);
		return (envp_copy);
	}
	else if (ft_strcmp(opt[0], "unset") == 0)
		handle_unset(opt, envp_copy);
	else if (ft_strcmp(opt[0], "env") == 0)
		handle_env(opt, envp_copy);
	else if (ft_strcmp(opt[0], "exit") == 0)
		handle_exit(line, opt, envp_copy);
	else
		freeopt(opt);
	return (envp_copy);
}
