#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/include/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_data
{
	char	*path;
	char	**path_split;
	char	*argvs_join;

}			t_data;

char	*rl_gets(void);
int		main(int argc, char **argv, char **envp);
void	parsing(int argc, char **argv, char **envp, t_data *data);
void	join_all_argv(char **argv, t_data *data);
void	search_split_path(char **envp, t_data *data);
void	split_path(t_data *data);
void	error_quotation(t_data *data);
void	search_last_quote(t_data *data, int i);
#endif
