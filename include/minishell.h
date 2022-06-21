#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/include/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_data
{
	char	*path;
	char	**path_split;

} t_data;


#endif
