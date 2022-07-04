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
	int				first;
	char			*cmd;
	char			**argv;
	char			**envp;
	struct s_cmd	*next;
}					t_cmd;

//envp_cp.c
char	**envp_cp(char **envp);

//handle_builtin.c
void	handle_builtin(char *line, char **envp);

//handle_cd.c
void	handle_cd(char **opt);

//handle_echo.c
void	handle_echo(char **opt);

//handle_env.c
void	handle_env(char **opt, char **envp_copy);

//handle_exit.c
void	handle_exit(char **opt);

//handle_export.c
void	handle_export(char **opt);

//handle_pwd.c
void	handle_pwd(char **opt);

//handle_unset.c
void	handle_unset(char **opt, char **envp_copy);

//minishell.c

//parsing.c
void	parsing(char *line, char **envp_copy, t_data *data);
void	split_line(char *line, t_data *data);

//pipex.c
void	pipex(t_cmd *cmd);
void	exec_cmd(t_cmd *cmd, int pipe_fd[2]);

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
