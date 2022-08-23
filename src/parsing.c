#include "../include/minishell.h"

void	parsing(char *line, char **envp_copy, t_data *data)
{
	sig_reset();
	access(envp_copy[0], F_OK);
	error_quotation(line, data);
	tokenize(line, data);
	status(data, line);
	env_split(data, envp_copy);
	//search_cmd(data);
	sig_handling();
}

void	tokenize(char *line, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->line_lenght = ft_strlen(line);
	printf("l_len = %d\n", data->line_lenght);
	findlenght(line, data);
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_strchr(QUOTES, line[i]))
			i = quote(i, line);
		if (ft_strchr(WS_METACHAR, line[i]))
		{
			data->indexmeta[j] = line[i];
			line[i] = '\0';
			j++;
		}
		i++;
	}
	printf("indexmeta: %s\n", data->indexmeta);
	printf("data->line_length: %i\n", data->line_lenght);
	print_line(line, data);
}

int	quote(int i, char *line)
{
	if (ft_strchr("\'", line[i]))
	{
		i++;
		while (!ft_strchr("\'", line[i]))
		{
			i++;
		}
	}
	if (ft_strchr("\"", line[i]))
	{
		i++;
		while (!ft_strchr("\"", line[i]))
		{
			i++;
		}
	}
	i++;
	return (i);
}

void	findlenght(char *line, t_data *data)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = 0;
	while (line[i] != '\0')
	{
		if (ft_strchr(QUOTES, line[i]) && line[i])
			i = quote(i, line);
		if (ft_strchr(WS_METACHAR, line[i]) && line[i])
		{
			printf("in strchr line[%d] = %c\n", i, line[i]);
			lenght++;
		}
		i++;
	}
	printf("lenght = %d\n", lenght);
	data->indexmeta = ft_calloc(lenght + 1, sizeof (char));
}

// ecrit la ligne avec les \0
void	print_line(char *line, t_data *data)
{
	int i;
	int	len;

	i = 0;
	len = data->line_lenght;
	while (len > 0)
	{
		if (line[i] == '\0')
		{
			printf("\n");
		}
		printf("%c", line[i]);
		i++;
		len--;
	}
	printf("\n");
}
