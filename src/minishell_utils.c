/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:19:43 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:19:47 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

void	restore_std(t_data *data)
{
	dup2(data->stdin_cp, STDIN_FILENO);
	dup2(data->stdout_cp, STDOUT_FILENO);
	close(data->stdin_cp);
	close(data->stdout_cp);
}
