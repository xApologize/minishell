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
	int		if_no_meta;
	char	*indexmeta;
	int		line_lenght;
	bool	error_status;
	bool	error_quotes;
	bool	error_first_cmd;
	int		redir_bool;
}			t_data;

//cmd = path au complet. ex: /usr/bin/cat, le access.
//argv = le split de la command. ex argv[0] : cat, argv[1] : file, argv[2] : NULL.
//environ = envp/environ du main.
//next = la prochaine node.
typedef struct s_cmd
{
	int				redir;
	char			*cmd;
	char			**argv;
	char			**env;
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

//heredoc.c
void	heredoc(char *delimiter, int fd);

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
void	parsing(char *line, char **envp_copy, t_data *data, t_cmd *cmd);
void	tokenize(char *line, t_data *data);

// parsing_utils.c
int		quote(int i, char *line);
void	check_pipe(char *line, t_data *data);
void	tokenize_quote(char *line, t_data *data);
void	findlenght(char *line, t_data *data);
void	print_line(char *line, t_data *data);

//pipex.c
void	pipex(t_cmd *cmd);
void	exec_cmd(t_cmd *cmd);
void	redir(t_cmd *cmd);

//quotation.c
bool	error_quotation(char *line, t_data *data);
int		squotes(char *line, int i, t_data *data);
int		dquotes(char *line, int i, t_data *data);

//rl_gets.c
char	*rl_gets(void);

//search_cmd.c
void	search_cmd(t_data *data, char *line, t_cmd *cmd);
void	env_split(t_data *data, char **envp_copy);
void	trim_path(t_data *data);

//set_exec_struct
void	set_exec_struct(char *line, t_cmd *cmd, t_data *data, char **env);
int		nb_pipes(t_data *data);
t_cmd 	*create_nodes(char **env);
void 	add_nodes(t_cmd **cmd, t_cmd *new_cmd);
t_cmd 	*get_last(t_cmd *cmd);

//sig_handling.c
void	sig_handling(void);

//sig_reset.c
void	sig_reset(void);

//sigint_handler.c
void	sigint_handler(int signum);

//status_error.c
void	status(t_data *data, char *line);
#endif
