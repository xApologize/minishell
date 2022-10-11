#include "../include/minishell.h"
//returns true if string contains a valid $ for expanding
bool	check_dollar(char *line)
{
	int		i;
	bool	quote;

	i = -1;
	quote = false;
	while (line[++i])
	{
		if (line[i] == '\'' && quote == false)
		{
			quote = true;
			i++;
		}
		if (line[i] == '$' && (ft_isalnum(line[i + 1]) == 1 \
		|| line[i + 1] == '_') && quote == false)
			return (true);
		if (line[i] == '\'' && quote == true)
			quote = false;
	}
	return (false);
}

//returns the expanded line. Copies char by char. if it encounters an expansion it finds it and adds it to the string. if not found, adds nothing
char	*unwrap_dollar(char *line)
{
	char	*new_line;
	char	*value;
	int		trigger;

	trigger = 0;
	new_line = ft_calloc(10, 1);
	while (*line)
	{
		if (*line == '\'' && trigger == 1)
			trigger = 0;	
		if (*line == '\'' && trigger == 0)
			trigger = 1;
		while (*line == '$' && trigger == 0 && check_dollar(line))
		{
			value = return_dollar(line);
			new_line = ft_strjoinfree(new_line, value);
			free(value);
			value = NULL;
			line = skip_dollar(line);
		}
		new_line = charjoinfree(new_line, *line);
		line++;
	}
	return (new_line);
}

//skips the expansion so it is not copied into the new string
char	*skip_dollar(char *line)
{
	while (++line)
	{
		if (ft_isalnum(*line) == 0)
			break ;
	}
	return (line);
}

bool	check_question(char *line)
{
	int		i;
	bool	quote;

	i = -1;
	quote = false;
	while (line[++i])
	{
		if (line[i] == '\'')
		{
			quote = true;
			i++;
		}
		if (line[i] == '$' && line[i + 1] == '?' && quote == false)
			return (true);
		if (line[i] == '\'' && quote == true)
			quote = false;
	}
	return (false);	
}

char	*unwrap_enigma(char *line)
{
	char	*new_line;
	char	*value;
	int		trigger;

	trigger = 0;
	new_line = ft_calloc(10, 1);
	while (*line)
	{
		if (*line == '\'' && trigger == 1)
			trigger = 0;	
		if (*line == '\'' && trigger == 0)
			trigger = 1;
		while ((*line == '$' && *(line + 1) == '?') && trigger == 0)
		{
			value = ft_itoa(*get_exit_code());
			new_line = ft_strjoinfree(new_line, value);
			free(value);
			value = NULL;
			line += 2;
		}
		new_line = charjoinfree(new_line, *line);
		line++;
	}
	return (new_line);
}