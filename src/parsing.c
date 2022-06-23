#include "../include/minishell.h"

void	parsing(int argc, char **argv, char **envp, t_data *data)
{
	(void)argc;
	search_split_path(envp, data);
	join_all_argv(argv, data);
	error_quotation(data);
}

void	join_all_argv(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[i + 1] != NULL)
	{
		data->argvs_join = ft_strjoin(argv[i], argv[i + 1]);
		i++;
	}
}