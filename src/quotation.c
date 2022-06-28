#include "../include/minishell.h"

// void	error_quotation(t_data *data)
// {
// 	int		i;
// 	bool	pair;

// 	i = 0;
// 	pair = true;
// 	while (data->argvs_join[i] != '\0')
// 	{
// 		if (data->argvs_join[i] == '\'') // retour de readline au lieu de data->argvs_join
// 		{
// 			if (pair == true)
// 				pair = false;
// 			else
// 				pair = true;
// 			i++;
// 		}
// 		i++;
// 	}
// 	if (pair == false)
// 		search_last_quote(data, i);
// }

// void	search_last_quote(t_data *data, int i)
// {
// 	while (data->argvs_join[i] != '\'')
// 		i--;
	
// }