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
# include <signal.h>
# include <string.h>
//# include "/opt/homebrew/Cellar/readline/8.1.2/include/readline/readline.h"

// option de compil macos + homebrew: gcc minishell.c rl_gets.c  -lreadline -L /opt/homebrew/Cellar/readline/8.1.2/lib -I /opt/homebrew/Cellar//readline/8.1.2/include

typedef struct s_data
{
	char	**path_split;
	char	**line_split;
	char	**cmd_tab;

}			t_data;

typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
}					t_struct;

void	sigint_handler(int signum);
char	*rl_gets(void);
int		main(int argc, char **argv, char **envp);
void	parsing(char *line, char **envp, t_data *data);
void	split_path(t_data *data);
void	error_quotation(t_data *data);
void	search_last_quote(t_data *data, int i);
void	search_cmd(t_data *data);
void	split_line(char *line, t_data *data);
void	env_split(t_data *data);
void	trim_path(t_data *data);

#endif
