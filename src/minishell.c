#include "../include/minishell.h"
extern char **g_envp_copy;

// need to fix prompt that shows up twice when using ctrl-c when signal is reset
int	main(void)
{
	t_data		data;
	t_cmd		*cmd;
	extern char	**environ;

	g_envp_copy = envp_cp(environ);
	update_shlvl();
	print_intro();
	cmd = NULL;
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
