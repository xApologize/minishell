#include "../include/minishell.h"

void	update_pwd(char *pwd, char **envp_copy)
{
	int index;

	index = find_pwd(envp_copy);
	if (index != -1)
	{
		free(envp_copy[index]);
		envp_copy[index] = ft_strjoinfree("PWD=", pwd);
	}
}