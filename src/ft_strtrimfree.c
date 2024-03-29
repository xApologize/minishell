/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:18:11 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:18:14 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

extern char	**g_envp_copy;

//same as ft_strtrim but frees string given as argument
static int	ft_isinset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_getstart(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (ft_isinset(set, s1[start]) == 1)
		start++;
	return (start);
}

static size_t	ft_getend(char const *s1, char const *set)
{
	size_t	end;
	size_t	i;

	end = ft_strlen(s1) - 1;
	i = 0;
	while (ft_isinset(set, s1[end]) == 1)
	{
		end--;
		i++;
	}
	return (i);
}

char	*ft_strtrimfree(const char *s1, const char *set)
{
	char	*nstr;
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	len = ft_strlen(s1);
	if (start >= (len - end))
		return (ft_strdup(""));
	nstr = malloc(((len - start - end) + 1) * sizeof(char));
	if (nstr == NULL)
		return (NULL);
	i = -1;
	while ((++i + start) < (len - end))
		nstr[i] = s1[i + start];
	nstr[i] = '\0';
	free((void *) s1);
	return (nstr);
}
