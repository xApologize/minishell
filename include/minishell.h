#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/include/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <string.h>
# include "readline/readline.h"
# include "readline/history.h"
# include <stdbool.h>
# include <signal.h>
# include <string.h>

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
void	sig_handling(void);
void	handle_builtin(char *line, char **envp);
void	handle_cd(char **opt);
void	handle_echo(char **opt);
void	handle_env(char **opt, char **envp_copy);
void	handle_exit(char **opt);
void	handle_export(char **opt);
void	handle_pwd(char **opt);
void	handle_unset(char **opt, char **envp_copy);
void	parsing(char *line, char **envp_copy, t_data *data);
void	split_path(t_data *data);
void	error_quotation(t_data *data);
void	search_last_quote(t_data *data, int i);
void	search_cmd(t_data *data);
void	split_line(char *line, t_data *data);
void	env_split(t_data *data);
void	trim_path(t_data *data);
char	**envp_cp(char **envp);

#endif
