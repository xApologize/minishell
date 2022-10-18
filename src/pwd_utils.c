/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:24:04 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:24:06 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern char	**g_envp_copy;

//finds and prints the currrent working directory
void	handle_pwd(t_cmd *cmd)
{
	int		args;
	char	*path;

	path = NULL;
	args = 0;
	while (cmd->argv[args])
		args++;
	if (args > 1)
	{
		ft_putstr_fd("pwd: too many arguments\n", STDERR_FILENO);
		set_exit_code(1);
	}
	else
	{
		path = getcwd(path, 0);
		if (path)
		{
			printf("%s\n", path);
			free(path);
			set_exit_code(0);
		}
		else
			set_exit_code(1);
	}
}
