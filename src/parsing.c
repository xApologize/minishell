#include "../include/minishell.h"

void	parsing(char **envp_copy, t_cmd *cmd)
{
	error_quotation();
	tokenize();
	status();
	env_split(envp_copy);
	cmd = set_exec_struct(envp_copy);
	search_cmd(cmd);
}

void	tokenize()
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	_data.line_lenght = ft_strlen(_data.line);
	findlenght();
	i = 0;
	while (_data.line[i] != '\0')
	{
		if (ft_strchr(QUOTES, _data.line[i]))
			i = quote(i);
		if (ft_strchr(WS_METACHAR, _data.line[i]))
		{
			_data.indexmeta[j] = _data.line[i];
			_data.line[i] = '\0';
			j++;
		}
		i++;
	}
}

int	quote(int i)
{
	if (ft_strchr("\'", _data.line[i]))
	{
		i++;
		while (!ft_strchr("\'", _data.line[i]))
		{
			i++;
		}
	}
	if (ft_strchr("\"", _data.line[i]))
	{
		i++;
		while (!ft_strchr("\"", _data.line[i]))
		{
			i++;
		}
	}
	i++;
	return (i);
}

void	findlenght()
{
	int	i;
	int	lenght;

	i = 0;
	lenght = 0;
	while (_data.line[i] != '\0')
	{
		if (ft_strchr(QUOTES, _data.line[i]) && _data.line[i])
			i = quote(i);
		if (ft_strchr(WS_METACHAR, _data.line[i]) && _data.line[i])
			lenght++;
		i++;
	}
	_data.indexmeta = ft_calloc(lenght + 1, sizeof (char));
}
