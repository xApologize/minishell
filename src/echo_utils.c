/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:17:17 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:17:18 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

//prints the given arguments out followed by
//a \n by default. if n option used newline is omitted.

void	print_n(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->argv[++i])
	{
		if (check_n(cmd->argv[i]) == 0)
			break ;
	}
	while (cmd->argv[++i])
	{
		printf("%s", cmd->argv[i]);
		if (cmd->argv[i + 1])
			printf(" ");
	}
}

void	print_no_n(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->argv[++i])
	{
		printf("%s", cmd->argv[i]);
		if (cmd->argv[i + 1])
			printf(" ");
	}
	printf("\n");
}

void	handle_echo(t_cmd *cmd)
{
	if (cmd->argv[1])
	{
		if (check_n(cmd->argv[1]) == 1)
			print_n(cmd);
		else
			print_no_n(cmd);
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
		if (trigger == 0 && (ft_isalnum(line[i]) == 1
				|| ft_strchr("<>|", line[i])))
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
