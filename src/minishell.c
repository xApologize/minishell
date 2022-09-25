#include "../include/minishell.h"

// need to add return status code to builtins
// need to fix prompt that shows up twice when using ctrl-c when signal is reset
int	main(void)
{
	t_data		data;
	t_cmd		*cmd;
	extern char	**environ;

	g_envp_copy = envp_cp(environ);
	print_intro();
	sig_handling();
	cmd = NULL;
	while (1)
	{
		data.line = rl_gets();
		if (data.line == NULL)
			exit(0);
		data.line = handle_dollar(data.line);
		parsing(&data, cmd);
	}
	return (0);
}
