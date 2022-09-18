#include "../include/minishell.h"

void free_data(void)
{
	free(_data.indexmeta);
	free(_data.line);
	freeopt(_data.line_split);
	freeopt(_data.path_split);
}