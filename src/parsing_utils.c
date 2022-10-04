#include "../include/minishell.h"

void	env_split(t_data *data)
{
	int		find;
	char	*tmp;

	find = 0;
	data->path_split = NULL;
	while (g_envp_copy[find])
	{
		if (ft_strncmp(g_envp_copy[find], "PATH=", 5) == 0)
			break ;
		find++;
	}
	if (g_envp_copy[find] != NULL)
		data->path_split = ft_split(g_envp_copy[find], ':');
	tmp = ft_strdup(data->path_split[0]);
	free(data->path_split[0]);
	data->path_split[0] = ft_substr(tmp, 5, ft_strlen(tmp) - 5);
	free(tmp);
}

char	*charjoin(const char *s1, const char c)
{
	char	*newstring;
	int		len;

	len = ft_strlen(s1);
	newstring = ft_calloc(len + 2, sizeof(char));
	len = 0;
	while (s1[len])
	{
		newstring[len] = s1[len];
		len++;
	}
	newstring[len] = c;
	newstring[len + 1] = '\0';
	s1 = NULL;
	return (newstring);
}

void	set_trigger_on(int *i, int *trigger, t_data *data)
{
	*trigger = 1;
	if ((data->line[*i] == '<' && data->line[*i + 1] == '<') \
		|| (data->line[*i] == '>' && data->line[*i + 1] == '>'))
		*i += 1;
	*i += 1;
}

void	print_parse_error(t_data *data)
{
	dprintf(STDERR_FILENO, "minicougar: syntax error near unexpected token '%s'", data->invalid_parse);
}