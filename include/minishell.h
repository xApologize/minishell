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

//cd_utils.c
void	handle_cd(char **opt, char **envp_copy);
void	update_pwd(char **envp_copy);
int		find_oldpwd(char **envp_copy);
int		find_pwd(char **envp_copy);

//echo_utils.c
void	handle_echo(char *line, char **opt);
void	print_echo_with_n(char *line);
void	print_echo_without_n(char *line);
int		skip_n(char *line);

//check_n.c
int		check_n(char *opt);

//handle_env.c
void	handle_env(char **opt, char **envp_copy);

//handle_exit.c
void	handle_exit(char *line, char **opt, char **envp_copy);

//export_utils.c
char	**handle_export(char *line, char **envp_copy);
bool	checkvalidenv(char *arg);
bool	checkvalidassign(bool env_stat, char *arg);
bool	checkassign(char *arg);
int		check_modify_env(char *arg, char **envp_copy);

//export_utils2.c
char	**addtoenv(char *arg, char **envp_copy);
char	**modify_var(char *arg, char **envp_copy);
int		check_dup_env(char *arg, char **envp_copy);

//unset_utils.c
char	**handle_unset(char **opt, char **envp_copy);
bool	checkvalidarg(char *arg);
void	modifyvar(char *var, char **envp_copy);
bool	checkifunset(char *var, char *envp_var);
char	**copynewenvp(char **envp_copy);
int		countnewvars(char **envp_copy);

//sig_utils.c
void	sig_handling(void);
void	sig_reset(void);
void	sigint_handler(int signum);

//pwd_utils.c
void	handle_pwd(char **opt);

//freeopt.c
void	freeopt(char **opt);

//pepe.c
void	pepe(void);

//print_intro.c
void	print_intro(void);

//find_var.c
int		find_var(char *arg, char **envp_copy);

//get_home.c
char	*get_home(char **envp_copy);

//minishell

//parsing.c
void	parsing(char *line, char **envp_copy, t_data *data);
void	find_cmds(char *line, t_data *data);

// parsing_utils.c
void	check_pipe(char *line, t_data *data);
void	tokenize_quote(char *line, t_data *data);

//pipex.c
void	pipex(t_cmd *cmd);
void	exec_cmd(t_cmd *cmd);
void	redir(t_cmd *cmd);

//quotation.c
void	error_quotation(t_data *data);
void	search_last_quote(t_data *data, int i);

//rl_gets.c
char	*rl_gets(void);

//search_cmd.c
void	search_cmd(t_data *data);
void	env_split(t_data *data, char **envp_copy);
void	trim_path(t_data *data);

//void	split_path(t_data *data);

//tab_create.c
int		nb_tabs(char *line);
int		nb_tabs_next(char *line, int nb_tab, int i);
int		find_nb_tb(char *line);
void	lines_lenght(char *line, t_data *data);
char	*allocation(int i, char *line, t_data *data);
void 	skip_ws(int i, char *line, t_data *data);
int		skip_quotes(int i, char *line, t_data *data);

//dollar_sign.c
bool	check_dollar(char *line);

//handle_dollar.c
char	*handle_dollar(char *line, char **envp_copy);

//unwrap_dollar.c
char	*unwrap_dollar(char *line, char **envp_copy);

//skip_single_quote.c
void	skip_single_quote(char *line);

//return_dollar.c
char	*return_dollar(char *line, char **envp_copy);

//return_var.c
char	*return_var(char *line);

//charjoinfree.c
char	*charjoinfree(const char *s1, const char c);

//skip_dollar.c
char	*skip_dollar(char *line);
#endif
