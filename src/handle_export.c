#include "../include/minishell.h"

// readline, rl_clear_history, rl_on_new_line,
// rl_replace_line, rl_redisplay, add_history,
// printf, malloc, free, write, access, open, read,
// close, fork, wait, waitpid, wait3, wait4, signal,
// sigaction, sigemptyset, sigaddset, kill, exit,
// getcwd, chdir, stat, lstat, fstat, unlink, execve,
// dup, dup2, pipe, opendir, readdir, closedir,
// strerror, perror, isatty, ttyname, ttyslot, ioctl,
// getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
// tgetnum, tgetstr, tgoto, tputs

void	handle_export(char **opt, char **envp_copy)
{
	int args;

	args = 0;
	while (opt[args])
		args++;
	if (args > 1)
		ft_putstr_fd("export: too many arguments\n", STDERR_FILENO);
	else
	{
		args = 0;
		while (envp_copy[args])
		{
			printf("declare -x %s\n", envp_copy[args]);
			args++;
		}
	}
}