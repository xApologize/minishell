/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:19:31 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:19:34 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

char	**g_envp_copy;

// need to fix prompt that shows up twice when using ctrl-c when signal is reset
int	main(int argc, char **argv)
{
	t_data		data;
	t_cmd		*cmd;
	extern char	**environ;

	g_envp_copy = envp_cp(environ);
	update_shlvl();
	cmd = NULL;
	if (argc >= 3 && !ft_strncmp(argv[1], "-c", 3))
	{
		int *exit_code;
		data.line = ft_strjoin(argv[2], "\n");
    	parsing(&data, cmd);
		exit_code = get_exit_code();
    	exit(*exit_code);
	}
	print_intro();
	while (1)
	{
		sig_handling();
		data.line = rl_gets();
		if (data.line == NULL)
		{
			free_the_pp(g_envp_copy);
			exit(0);
		}
		parsing(&data, cmd);
	}
	return (0);
}
