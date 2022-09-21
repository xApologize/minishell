#include "../include/minishell.h"

void free_data(t_data *data)
{
	free(data->save_line);
	free(data->save_indexmeta);
	freeopt(data->line_split);
	freeopt(data->path_split);
}
