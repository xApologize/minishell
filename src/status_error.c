#include "../include/minishell.h"

void	status_error(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (data->error_quotes == true)
		dprintf(2, "quotes is odd\n");
	// if (data->error_first_cmd == true)
	// {
	// 	dprintf(2, "%s:", strerror(errno));
	// 	while (line[i] != '\0')
	// 		dprintf(2, "%c", line[i++]);
	// 	// regarder pour commande not found perror
	// 	printf("\n");
	// }
}