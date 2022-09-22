#include "../include/minishell.h"

void free_data(t_data *data)
{
	data->indexmeta = data->save_indexmeta;
	free(data->indexmeta);
	data->line = data->save_line;
	free(data->line);
	free_the_pp(data->path_split);
	rl_clear_history();
}
