#include "include/minishell.h"

void	parsing(int argc, char **argv, char **envp, t_data *data)
{
	search_split_path(envp, data);
}