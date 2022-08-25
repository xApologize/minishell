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

int	main(void)
{
	char		*line;
	t_data		data;
	t_cmd		*cmd;
	extern char	**environ;
	char		**envp_copy;

	envp_copy = envp_cp(environ);
	cmd = malloc(sizeof(t_cmd));
	print_intro();
	sig_handling();
	while (1)
	{
		line = rl_gets();
		if (line == NULL)
			exit(0);
		envp_copy = handle_builtin(line, envp_copy);
		parsing(line, envp_copy, &data, cmd);
		free(line);
	}
	return (0);
}
