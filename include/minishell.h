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
# define PIPE_READ 0
# define PIPE_WRITE 1
# define METACHAR "|<>\n"
# define WS "\v\t\n\f\r "
# define DEBUG printf("debug\n");
# define WS_METACHAR "|<>\n\v\t\n\f\r "
# define QUOTES "\'\""

typedef struct s_data
{
	char	**path_split;
	char	**line_split;
	int		nb_tab;
	char	**cmd_tab;
	char	*cmd_line;
	int		l_t;
	int		if_no_meta;
}			t_data;

//cmd = path au complet. ex: /usr/bin/cat, le access.
//argv = le split de la command. ex argv[0] : cat, argv[1] : file, argv[2] : NULL.
//environ = envp/environ du main.
//next = la prochaine node.
typedef struct s_cmd
{
	char			*cmd;
	char			**argv;
	char			**environ;
	struct s_cmd	*next;
}					t_cmd;

//clear_whitespace.c
int		clear_whitespace(int i, char *str);

//envp_cp.c
char	**envp_cp(char **envp);

//handle_builtin
char	**handle_builtin(char *line, char **envp);

//handle_cd.c
void	handle_cd(char **opt);

//handle_echo
void	handle_echo(char *line, char **opt);

//handle_env.c
void	handle_env(char **opt, char **envp_copy);

//handle_exit
void	handle_exit(char *line, char **opt, char **envp_copy);

//handle_export
char	**handle_export(char **opt, char **envp_copy);

//handle_pwd.c
void	handle_pwd(char **opt);

//handle_unset.c
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
int		checkvalidenv(char *arg);

//print_intro
void	print_intro(void);

//check_n
int		check_n(char *opt);

//minishell

//parsing.c
void	parsing(char *line, char **envp_copy, t_data *data);
void	find_cmds(char *line, t_data *data);

// parsing_utils.c
void	check_pipe(char *line, t_data *data);
void	tokenize_quote(char *line, t_data *data);

//pipex.c
void	pipex(t_cmd *cmd);
void	pipex_redir(t_cmd *cmd);
void	exec_cmd(t_cmd *cmd);

//quotation.c
void	error_quotation(t_data *data);
void	search_last_quote(t_data *data, int i);

//rl_gets.c
char	*rl_gets(void);

//search_cmd.c
void	search_cmd(t_data *data);
void	env_split(t_data *data, char **envp_copy);
void	trim_path(t_data *data);

//sig_handling.c
void	sig_handling(void);

//sig_reset.c
void	sig_reset(void);

//sigint_handler.c
void	sigint_handler(int signum);

//void	split_path(t_data *data);

//singleton_statuscode.c
int		*get_exit_code(void);
void	set_exit_code(int status_code);

//tab_create.c
int		nb_tabs(char *line);
int		nb_tabs_next(char *line, int nb_tab, int i);
int		find_nb_tb(char *line);
void	lines_lenght(char *line, t_data *data);
char	*allocation(int i, char *line, t_data *data);
void 	skip_ws(int i, char *line, t_data *data);
int		skip_quotes(int i, char *line, t_data *data);
#endif
