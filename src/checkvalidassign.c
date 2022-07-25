#include "../include/minishell.h"

bool	checkvalidassign(bool env_stat, char *arg)
{
	bool is_valid;

	is_valid = checkassign(arg);
	if (!env_stat)
	{
		dprintf(STDERR_FILENO, "msh: export: '%s': not a valid identifier\n", arg);
		return (false);
	}
	else if (!is_valid)
		return (false);
	return (true);
}