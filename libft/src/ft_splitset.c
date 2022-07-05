/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:19:02 by yst-laur          #+#    #+#             */
/*   Updated: 2022/04/11 20:19:07 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_strchrint(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static char	**memerr(char **str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		free(str[index]);
		index++;
	}
	free(str);
	return (NULL);
}

static size_t	wordcount(const char *s, char *set)
{
	size_t	count;
	size_t	trigger;

	count = 0;
	trigger = 0;
	while (*s)
	{
		if (ft_strchrint(set, *s) == 0 && trigger == 0)
		{
			count++;
			trigger = 1;
		}
		if (ft_strchrint(set, *s) == 1 && trigger == 1)
			trigger = 0;
		s++;
	}
	return (count);
}

static size_t	nextword(const char *s, char *set, size_t *i)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = *i;
	while (ft_strchrint(set, s[index]) == 1)
		index++;
	while (s[index])
	{
		if (ft_strchrint(set, s[index]) == 0)
		{
			count++;
			index++;
		}
		if (ft_strchrint(set, s[index]) == 1)
		{
			*i = index;
			return ((count + 1));
		}
	}
	*i = index;
	return (count + 1);
}

char	**ft_splitset(const char *s, char *set)
{
	char	**str;
	size_t	wc;
	size_t	index;
	size_t	i;
	size_t	size;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	wc = wordcount(s, set);
	str = malloc((wc + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (i < wc)
	{
		size = nextword(s, set, &index);
		str[i] = ft_substr(s, (index - (size - 1)), (size - 1));
		if (str[i] == NULL)
			return (memerr(str));
		i++;
	}
	str[i] = NULL;
	return (str);
}
