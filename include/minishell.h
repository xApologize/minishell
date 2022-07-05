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

//envp_cp
char	**envp_cp(char **envp);

//handle_builtin
char	**handle_builtin(char *line, char **envp);

//handle_cd
void	handle_cd(char **opt);

//handle_echo
void	handle_echo(char *line, char **opt);

//handle_env
void	handle_env(char **opt, char **envp_copy);

//handle_exit
void	handle_exit(char *line, char **opt, char **envp_copy);

//handle_export
char	**handle_export(char **opt, char **envp_copy);

//handle_pwd
void	handle_pwd(char **opt);

//handle_unset
void	handle_unset(char **opt, char **envp_copy);

//freeopt
void	freeopt(char **opt);

//pepe
void	pepe(void);

//print_echo_with_n
void	print_echo_with_n(char *line);

//print_echo_without_n
void	print_echo_without_n(char *line);

//addtoenv
char	**addtoenv(char *arg, char **envp_copy);

//checkvalidenv
int	checkvalidenv(char *arg);

//print_intro
void	print_intro(void);

//check_n
int	check_n(char *opt);

//minishell

//parsing
void	parsing(char *line, char **envp_copy, t_data *data);
void	split_line(char *line, t_data *data);

//quotation.c
void	error_quotation(t_data *data);
void	search_last_quote(t_data *data, int i);

//rl_gets.c
char	*rl_gets(void);

//search_cmd.c
void	search_cmd(t_data *data);
void	env_split(t_data *data);
void	trim_path(t_data *data);

//sig_handling.c
void	sig_handling(void);

//sigint_handler.c
void	sigint_handler(int signum);

//void	split_path(t_data *data);

#endif
