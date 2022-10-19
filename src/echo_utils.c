/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:17:17 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:17:18 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

//prints the given arguments out followed by
//a \n by default. if n option used newline is omitted.

void	print_n(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->argv[++i])
	{
		if (check_n(cmd->argv[i]) == 0)
			break ;
	}
	while (cmd->argv[i])
	{
		printf("%s", cmd->argv[i]);
		if (cmd->argv[i + 1])
			printf(" ");
		i++;
	}
}

void	print_no_n(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->argv[++i])
	{
		printf("%s", cmd->argv[i]);
		if (cmd->argv[i + 1])
			printf(" ");
	}
	printf("\n");
}

void	handle_echo(t_cmd *cmd)
{
	if (cmd->argv[1])
	{
		if (check_n(cmd->argv[1]) == 1)
			print_n(cmd);
		else
			print_no_n(cmd);
	}
	else
		printf("\n");
	set_exit_code(0);
}

int	check_n(char *opt)
{
	int	i;

	i = 0;
	if (opt[0] != '-')
		return (0);
	else
	{
		while (opt[++i])
			if (opt[i] != 'n')
				return (0);
	}
	return (1);
}
