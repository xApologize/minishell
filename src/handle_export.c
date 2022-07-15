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

char	**handle_export(char *line, char **envp_copy)
{
	int	i;
	char	**opt;

	i = 0;
	opt = ft_split(line, ' ');
	while (opt[++i])
	{
		if (checkvalidenv(opt[i]) == 1 && check_modify_env(opt[i], envp_copy) == 1)
		{
			printf("Entered modify env\n");
			envp_copy = modify_var(opt[i], envp_copy);
		}
		if (checkvalidenv(opt[i]) == 1 && check_dup_env(opt[i], envp_copy) == 0)
		{
			printf("Entered valid env\n");
			envp_copy = addtoenv(opt[i], envp_copy);
		}
	}
	return (envp_copy);
}