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
int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_data	data;
	t_cmd	cmd;
	struct sigaction sa;

	(void)argc;
	(void)argv;
	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	while (1)
	{
		line = rl_gets();
		if (strcmp(line, "exit") == 0)
			exit(0);
	}
	parsing(line, &data, &cmd);
	return (0);
}
