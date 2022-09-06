#include "../include/minishell.h"

void	parsing(char **envp_copy, t_data *data, t_cmd *cmd)
{
	sig_reset();
	error_quotation(data);
	tokenize(data);
	status(data);
	env_split(data, envp_copy);
	cmd = set_exec_struct(data, envp_copy);
	search_cmd(data, cmd);
	sig_handling();
}

void	tokenize(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->line_lenght = ft_strlen(data->line);
//	printf("l_len = %d\n", data->line_lenght);
	findlenght(data);
	i = 0;
	while (data->line[i] != '\0')
	{
		if (ft_strchr(QUOTES, data->line[i]))
			i = quote(i, data);
		if (ft_strchr(WS_METACHAR, data->line[i]))
		{
			data->indexmeta[j] = data->line[i];
			data->line[i] = '\0';
			j++;
		}
		i++;
	}
//	printf("%s\n", data->indexmeta);
//	print_line(line, data);
}

int	quote(int i, t_data *data)
{
	if (ft_strchr("\'", data->line[i]))
	{
		i++;
		while (!ft_strchr("\'", data->line[i]))
		{
			i++;
		}
	}
	if (ft_strchr("\"", data->line[i]))
	{
		i++;
		while (!ft_strchr("\"", data->line[i]))
		{
			i++;
		}
	}
	i++;
	return (i);
}

void	findlenght(t_data *data)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = 0;
	while (data->line[i] != '\0')
	{
		if (ft_strchr(QUOTES, data->line[i]) && data->line[i])
			i = quote(i, data);
		if (ft_strchr(WS_METACHAR, data->line[i]) && data->line[i])
		{
			//printf("in strchr line[%d] = %c\n", i, line[i]);
			lenght++;
		}
		i++;
	}
	//printf("lenght = %d\n", lenght);
	data->indexmeta = ft_calloc(lenght + 1, sizeof (char));
}

// ecrit la ligne avec les \0
void	print_line(t_data *data)
{
	int i;
	int	len;

	i = 0;
	len = data->line_lenght;
	while (len > 0)
	{
		if (data->line[i] == '\0')
		{
			printf(" ");
		}
		printf("%c", data->line[i]);
		i++;
		len--;
	}
	printf("\n");
}
