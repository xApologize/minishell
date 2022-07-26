#include "../include/minishell.h"

//Parsing for env variable
//Has to begin with a letter. Rest up to equal sign has to be alnum
//If the variable begins with a letter and the rest is alnum but
// there is no equal sign it will not cause an error but it will not do anything
//If the variable contains a character that is not alnum it will print an error message and not do anything
//If the variable is valid and followed by equal with nothing it will get added equalling nothing
char	**handle_export(char *line, char **envp_copy)
{
	int	i;
	char	**opt;
	bool	valid_env;
	bool	valid_assign;

	i = 0;
	opt = ft_split(line, ' ');
	while (opt[++i])
	{
		valid_env = checkvalidenv(opt[i]);
		valid_assign = checkvalidassign(valid_env, opt[i]);
		if (valid_assign == true && check_modify_env(opt[i], envp_copy) == 1)
			envp_copy = modify_var(opt[i], envp_copy);
		if (valid_assign == true && check_dup_env(opt[i], envp_copy) == 0)
			envp_copy = addtoenv(opt[i], envp_copy);
	}
	return (envp_copy);
}