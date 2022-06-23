#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data data;
	parsing(argc, argv, envp, &data);
}