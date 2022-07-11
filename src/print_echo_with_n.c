/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_echo_with_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:30:37 by jrossign          #+#    #+#             */
/*   Updated: 2022/07/11 15:30:38 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_echo_with_n(char *line)
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
	i++;
	while (ft_isalpha(line[i]) == 1)
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	str = ft_substr(line, i, (j - i));
	pstr = ft_strtrim(str, ' ');
	free(str);
	printf("%s", pstr);
	free(pstr);
}
