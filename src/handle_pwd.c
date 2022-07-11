/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:30:04 by jrossign          #+#    #+#             */
/*   Updated: 2022/07/11 15:30:06 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_pwd(char **opt)
{
	int		args;
	char	*path;

	path = NULL;
	args = 0;
	while (opt[args])
		args++;
	if (args > 1)
		ft_putstr_fd("pwd: too many arguments\n", STDERR_FILENO);
	else
	{
		path = getcwd(path, 0);
		printf("%s\n", path);
		free(path);
	}
}
