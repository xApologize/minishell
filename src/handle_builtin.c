/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:18:33 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:18:35 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern char	**g_envp_copy;

//dispatches builtin to appropriate function
void	handle_builtin(t_cmd *cmd, t_data *data)
{
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		handle_echo(cmd);
	else if (ft_strcmp(cmd->argv[0], "cd") == 0)
		handle_cd(cmd);
	else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		handle_pwd(cmd);
	else if (ft_strcmp(cmd->argv[0], "export") == 0)
		handle_export(cmd);
	else if (ft_strcmp(cmd->argv[0], "unset") == 0)
		handle_unset(cmd);
	else if (ft_strcmp(cmd->argv[0], "env") == 0)
		handle_env(cmd);
	else if (ft_strcmp(cmd->argv[0], "exit") == 0)
		handle_exit(cmd, data);
	else if (ft_strcmp(cmd->argv[0], "pepe") == 0)
		pepe();
	else if (ft_strcmp(cmd->argv[0], "owo") == 0)
		owo();
}
