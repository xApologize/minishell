#include "../include/minishell.h"

//priints the given arguments out followed by a \n by default. if n option used newline is omitted.
void	handle_echo(t_cmd *cmd)
{
	char	*line;

	if (cmd->argv[1])
	{
		line = make_line(cmd->argv);
		if (check_n(cmd->argv[1]) == 1)
			print_echo_with_n(line);
		else
			print_echo_without_n(line);
		free(line);
	}
	else
		printf("\n");
	set_exit_code(0);
}

//skips echo so it doesn't get printed
int	skip_echo(char *line)
{
	int	i;

	i = 0;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	while (ft_isalnum(line[i]) == 1)
		i++;
	return (i);
}

//skips multiple n options
int	skip_n(char *line)
{
	int	i;
	int	trigger;

	i = skip_echo(line);
	trigger = 0;
	while (line[i])
	{
		if (line[i] == '-')
			trigger = 1;
		if (trigger == 1 && (line[i] == ' ' || line[i] == '\t'))
			trigger = 0;
		if (trigger == 0 && ft_isalnum(line[i]) == 1)
			return (i);
		if (trigger == 1 && ft_isalnum(line[i]) == 1 && line[i] != 'n')
		{
			while (line[i] != ' ' && line[i] != '\t')
				i--;
			return (i);
		}
	i++;
	}
	return (-1);
}

//prints the arguments with a newline at the end
void	print_echo_with_n(char *line)
{
	int		i;
	int		j;
	char	*str;
	char	*pstr;

	i = skip_n(line);
	j = ft_strlen(line);
	str = ft_substr(line, i, (j - i));
	pstr = ft_strtrim(str, ' ');
	free(str);
	printf("%s", pstr);
	free(pstr);
}

//prints the arguments without a newline at the end
void	print_echo_without_n(char *line)
{
	int		i;
	int		j;
	char	*str;
	char	*pstr;

	i = 0;
	j = ft_strlen(line);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (ft_isalpha(line[i]) == 1)
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	str = ft_substr(line, i, (j - i));
	pstr = ft_strtrim(str, ' ');
	free(str);
	printf("%s\n", pstr);
	free(pstr);
}
