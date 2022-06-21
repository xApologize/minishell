/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:09:59 by jrossign          #+#    #+#             */
/*   Updated: 2022/04/26 11:07:11 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	string_length(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	trimming_length(char *s, char c)
{
	int	i;

	i = 0;
	while ((s[i] && s[i] != c) || (s[i] == c && s[i + 1] == c))
		i++;
	return (i);
}

static char	**ft_splitter(char **split, char *trimmed, char c, size_t counter)
{
	size_t	x;

	if (ft_strlen(trimmed) == 0)
	{
		split[0] = NULL;
		return (split);
	}
	x = 0;
	while (x < counter + 1)
	{
		split[x] = ft_substr(trimmed, 0, string_length(trimmed, c));
		split[x] = ft_memcpy(split[x], trimmed, string_length(trimmed, c));
		trimmed = trimmed + trimming_length(trimmed, c) + 1;
		x++;
	}
	return (split);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		c_counter;
	char	*trimmed;
	char	**split;

	i = 0;
	c_counter = 0;
	trimmed = ft_strtrim(s, c);
	if (!trimmed)
	{
		split = NULL;
		return (split);
	}
	while (trimmed[i])
	{
		if (trimmed[i] == c && trimmed[i + 1] != c)
			c_counter++;
		i++;
	}
	split = ft_calloc(c_counter + 2, sizeof(char *));
	split = ft_splitter(split, trimmed, c, c_counter);
	free(trimmed);
	return (split);
}
