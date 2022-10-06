#include "../include/minishell.h"
#include <unistd.h>

//exits the program and frees all memory
//test
//takes an int as an argument that's used to set exit_status_code before exiting
void	handle_exit(t_cmd *cmd, t_data *data)
{
	int	exit_status;

	exit_status = 0;
	if (count_args(cmd) > 2)
	{
		dprintf(STDERR_FILENO, "minicougar: exit: too many arguments\n");
		set_exit_code(1);
		return ;
	}
	if (count_args(cmd) == 2)
	{
		if (cmd->argv[1] && check_if_num(cmd->argv[1]) == true)
			exit_status = ft_atoi(cmd->argv[1]);
		else
			dprintf(STDERR_FILENO, "minicougar: exit: \
			%s: numeric argument required\n", cmd->argv[1]);
	}
	free_data(data);
	free_cmd(cmd);
	free_the_pp(g_envp_copy);
	close(data->stdin_cp);
	close(data->stdout_cp);
	if (exit_status >= 0 && exit_status <= 127)
		exit(exit_status);
	else
		exit(0);
}

bool	check_if_num(const char *n)
{
	int	i;

	i = -1;
	while (n[++i])
	{
		if (ft_isdigit(n[i]) == 0)
			return (false);
	}
	return (true);
}

int	count_args(t_cmd *cmd)
{
	int	count;

	count = -1;
	while (cmd->argv[++count])
	{
	}
	return (count);
}
