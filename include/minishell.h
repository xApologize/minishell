#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_data 
{

}	t_data;

# include "../libft/include/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <string.h>
# include "readline/readline.h"
# include "readline/history.h"

// option de compil macos + homebrew: gcc minishell.c rl_gets.c  -lreadline -L /opt/homebrew/Cellar/readline/8.1.2/lib -I /opt/homebrew/Cellar//readline/8.1.2/include

char	*rl_gets(void);
void	sigint_handler(int signum);
void	sig_handling(void);
void	handle_builtin(char *line, char **envp);
void	handle_cd(char **opt);
void	handle_echo(char **opt);
void	handle_env(char **opt, char **envp);
void	handle_exit(char **opt);
void	handle_export(char **opt);
void	handle_pwd(char **opt);
void	handle_unset(char **opt);
char	**envp_cp(char **envp);

#endif
