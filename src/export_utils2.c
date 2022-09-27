#include "../include/minishell.h"

//adds the new variable to the environment
void	addtoenv(char *arg)
{
	char	**new_envp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (g_envp_copy[i])
		i++;
	new_envp = malloc((i + 2) * sizeof(char *));
	while (g_envp_copy[++j])
		new_envp[j] = ft_strdup(g_envp_copy[j]);
	new_envp[i] = ft_strdup(strip_quotes(arg));
	new_envp[i + 1] = NULL;
	free_the_pp(g_envp_copy);
	g_envp_copy = new_envp;
}

//if the argument was already part of the environement variables, modifies it to the new value
void	modify_var(char *arg)
{
	int		index;
	char	**split_arg;
	char	*new_arg;

	index = find_var(arg);
	split_arg = ft_split(arg, '=');
	new_arg = NULL;
	if (split_arg[1][0] == '"' || split_arg[1][0] == '\'')
	{
		split_arg[1] = ft_strtrimfree(split_arg[1], "'\" ");
		new_arg = ft_strdup(split_arg[0]);
		new_arg = ft_strjoinfree(new_arg, "=");
		new_arg = ft_strjoinfree(new_arg, split_arg[1]);
		free(g_envp_copy[index]);
		g_envp_copy[index] = ft_strdup(new_arg);
		free(new_arg);
	}
	else
	{
		free(g_envp_copy[index]);
		g_envp_copy[index] = ft_strdup(arg);
	}
	free_the_pp(split_arg);
}

//checks if the argument is already in the environment variables
int	check_dup_env(char *arg)
{
	int		i;
	char	**split_arg;
	char	*new_arg;

	i = -1;
	split_arg = ft_split(arg, '=');
	new_arg = NULL;
	if (split_arg[1][0] == '"' || split_arg[1][0] == '\'')
	{
		split_arg[1] = ft_strtrimfree(split_arg[1], "'\" ");
		new_arg = ft_strdup(split_arg[0]);
		new_arg = ft_strjoinfree(new_arg, "=");
		new_arg = ft_strjoinfree(new_arg, split_arg[1]);
	}
	else
		new_arg = arg;
	while (g_envp_copy[++i])
		if (ft_strcmp(g_envp_copy[i], new_arg) == 0)
			return (1);
	if (split_arg[1][0] == '"' || split_arg[1][0] == '\'')
		free(new_arg);
	free_the_pp(split_arg);
	return (0);
}

bool	checkassign(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if ((ft_isalnum(arg[i]) == 1 || arg[i] == '"' \
			|| arg[i] == '\'') && arg[i + 1] == '=')
			return (true);
	}
	return (false);
}

char	*strip_quotes(char *arg)
{
	char	**split_arg;
	char	*new_arg;

	split_arg = ft_split(arg, '=');
	new_arg = NULL;
	if (split_arg[1][0] == '"' || split_arg[1][0] == '\'')
	{
		split_arg[1] = ft_strtrimfree(split_arg[1], "'\" ");
		new_arg = ft_strdup(split_arg[0]);
		new_arg = ft_strjoinfree(new_arg, "=");
		new_arg = ft_strjoinfree(new_arg, split_arg[1]);
		free_the_pp(split_arg);
		return (new_arg);
	}
	free_the_pp(split_arg);
	return (arg);
}
