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
	t_cmd		*cmd;
	extern char	**environ;

	_data.envp_copy = envp_cp(environ);
	print_intro();
	//sig_handling();
	cmd = NULL;
	while (1)
	{
		_data.line = rl_gets();
		if (_data.line == NULL)
			exit(0);
		//_data.line = handle_dollar(_data.line, _data.envp_copy);
		parsing(_data.envp_copy, cmd);
		//free(data.line);
	}
	return (0);
}
