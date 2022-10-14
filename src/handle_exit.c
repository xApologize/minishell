#include "../include/minishell.h"

//exits the program and frees all memory

//if first arg is numeric will not exit and give
//error message: bash: exit: too many arguments
//if first arg has a letter exit will work but will 
//print error message: bash: exit: 4324a: numeric argument required
static void	arg_error(void)
{
	printf("exit\n");
	dprintf(STDERR_FILENO, "minicougar: exit: too many arguments\n");
	set_exit_code(1);
}

static void	num_error(t_cmd *cmd, t_data *data)
{
	printf("exit\n");
	dprintf(STDERR_FILENO, "minicougar: exit: %s: \
numeric argument required\n", cmd->argv[1]);
	free_all(cmd, data);
	close(data->stdin_cp);
	close(data->stdout_cp);
	exit(255);
}

static void	normal_exit(t_cmd *cmd, t_data *data)
{
	free_all(cmd, data);
	close(data->stdin_cp);
	close(data->stdout_cp);
	printf("exit\n");
	exit(0);
}

void	handle_exit(t_cmd *cmd, t_data *data)
{
	//int				exit_status;
	unsigned char	status;

	//exit_status = 0;
	status = 0;
	if (count_args(cmd) == 1)
		normal_exit(cmd, data);
	if (count_args(cmd) > 2 && check_if_num(cmd->argv[1]) == true)
	{
		arg_error();
		return ;
	}
	if (count_args(cmd) >= 2 && check_if_num(cmd->argv[1]) == false)
		num_error(cmd, data);
	if (cmd->argv[1] && check_if_num(cmd->argv[1]) == true)
		status = ft_atoi(cmd->argv[1]);
	free_all(cmd, data);
	close(data->stdin_cp);
	close(data->stdout_cp);
	exit(status);
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
