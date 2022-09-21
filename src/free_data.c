#include "../include/minishell.h"

void free_data(t_data *data)
{
	free(data->indexmeta);
	free(data->line);
	freeopt(data->line_split);
	freeopt(data->path_split);
}
