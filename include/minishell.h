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
	char	*indexmeta;
	char	*line;
	char	*save_line;
	char	*save_indexmeta;
	char	*invalid_parse;
	bool	parse_status;
	int		stdin_cp;
	int		stdout_cp;
	int		if_no_meta;
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
	int				redir_in;
	int				redir_out;
	char			*cmd;
	char			**argv;
	char			**env;
	bool			is_builtin;
	struct s_cmd	*next;
}					t_cmd;

char		**g_envp_copy;

//cd_utils.c
int			find_oldpwd(void);
int			find_pwd(void);
void		update_pwd(char *home);
void		handle_cd(t_cmd *cmd);

//check_n.c
int			check_n(char *opt);

//checkenvformat.c
int			checkenvformat(char *var);

//checkvalidarg.c
bool		checkvalidarg(char *arg);

//clear_whitespace.c
int			clear_whitespace(int i, char *str);

//dollar_utils.c
char		*handle_dollar(char *line);
char		*return_dollar(char *line);
char		*return_var(char *line);
int			find_var(char *arg);
char		*charjoinfree(const char *s1, const char c);

//dollar_utils2.c
bool		check_dollar(char *line);
char		*unwrap_dollar(char *line);
char		*skip_dollar(char *line);

//echo_utils.c
void		handle_echo(t_cmd *cmd);
int			skip_echo(char *line);
int			skip_n(char *line);
void		print_echo_with_n(char *line);
void		print_echo_without_n(char *line);

//envp_cp.c
char		**envp_cp(char **envp);

//export_utils.c
void		handle_export(t_cmd *cmd);
bool		checkvalidenv(char *arg);
bool		checkvalidassign(bool env_stat, char *arg);
int			check_modify_env(char *arg);

//export_utils2.c
void		addtoenv(char *arg);
void		modify_var(char *arg);
int			check_dup_env(char *arg);
char		*strip_quotes(char *arg);
bool		checkassign(char *arg);

//free_memory.c
void		free_cmd(t_cmd *cmd);
void		free_data(t_data *data);
void		free_the_pp(char **pp);
void		free_data_cmd(t_cmd *cmd, t_data *data);

// ft_strtrimfree.c
char		*ft_strtrimfree(const char *s1, const char *set);

//get_home.c
char		*get_home(void);

//handle_builtin.c
void		handle_builtin(t_cmd *cmd, t_data *data);

//handle_env.c
void		handle_env(t_cmd *cmd);

//handle_exit.c
void		handle_exit(t_cmd *cmd, t_data *data);
bool		check_if_num(const char *n);
int			count_args(t_cmd *cmd);

//heredoc.c
int			heredoc(t_data *data);

//misc_utils.c
int			get_mem_len(char *arg);
char		*stripshit(char *arg);

//make_line.c
char		*make_line(char **argv);

//minishell_utils.c
void		restore_std(t_data *data);

//parsing.c
void		parsing(t_data *data, t_cmd *cmd);
void		tokenize(t_data *data);
int			quote(int i, t_data *data);
void		findlenght(t_data *data);
void		print_line(t_data *data);

//parsing_utils.c
void		env_split(t_data *data);
void		trim_path(t_data *data);
void		set_trigger_on(int *i, int *trigger, t_data *data);
void		print_parse_error(t_data *data);

//pipex.c
void		pipex(t_cmd *cmd, t_data *data);
int			pipex_redir(t_cmd *cmd, t_data *data);
int			exec_fork_cmd(t_cmd	*cmd, t_data *data);
void		exec_cmd(t_cmd *cmd, t_data *data);
int			table_length(t_cmd *cmd);

//pipex_utils.c
void		redir_utils(t_cmd *cmd);
void		close_fork_fd(t_cmd *cmd);
int			handle_pipe_cmd(t_cmd *cmd, t_data *data);
void		wait_child(int *pid_child, int table_size);

//print_intro.c
void		print_intro(void);
void		pepe(void);

//pwd_utils.c
void		handle_pwd(t_cmd *cmd);

//quit_handle.c
void		quit_handling(int signum);

//quotation.c
void		error_quotation(t_data *data);
void		double_check(t_data *data);
void		single_check(t_data *data);

//rl_gets.c
char		*rl_gets(void);

//search_cmds.c
char		*get_path(char *line_cp, t_data *data);
int			get_argv_count(t_data *data);
char		**get_argv(t_data *data);
int			set_cmd(t_cmd *cmd, t_data *data);
void		search_cmd(t_data *data, t_cmd *cmd);

//search_cmds_cmd_utils.c
char		*access_absolute_path(char *line);
char		*access_relative_path(char *line);
char		*get_path(char *line_cp, t_data *data);
int			get_argv_count(t_data *data);
char		**get_argv(t_data *data);

//search_cmds_fd_utils.c
void		set_fd_in(t_cmd *cmd, t_data *data);
void		set_fd_out(t_cmd *cmd, int append, t_data *data);
void		get_fd(t_cmd *cmd, t_data *data, char meta);
void		close_fd(t_cmd *cmd);

//search_cmd_utils.c
void		handle_single_builtin(t_cmd *cmd, t_data *data);
void		skip_char(t_data *data);
char		*access_path(char *line);

//set_exec_struct.c
t_cmd		*set_exec_struct(t_data *data);
int			nb_pipes(t_data *data);
t_cmd 		*create_nodes(char **env);
void 		add_nodes(t_cmd **cmd, t_cmd *new_cmd);
t_cmd 		*get_last(t_cmd *cmd);

//sig_utils.c
void		sig_reset(void);
void		sig_handling(void);
void		sigint_handler(int signum);
void		quiet_handling(void);
void		shush(int signum);

//singleton_statuscode.c
int			*get_exit_code(void);
void		set_exit_code(int status_code);

//unset_utils.c
void		handle_unset(t_cmd *cmd);
bool		checkifunset(char *var, char *envp_var);
void		copynewenvp(void);
int			countnewvars(void);
void		modifyvar(char *var);

#endif
