#include "../include/minishell.h"

void free_data(t_data *data)
{
	data->indexmeta -= data->indexmeta_length;
	free(data->indexmeta);
	data->line -= data->line_lenght;
	free(data->line);
	freeopt(data->path_split);
}
