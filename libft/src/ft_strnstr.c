/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:34:37 by jrossign          #+#    #+#             */
/*   Updated: 2022/06/02 13:45:26 by jean-beno        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_check(const char *haystack, const char *needle, size_t len,
		int needlelen)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i] == needle[j] && i < len)
			{
				i++;
				j++;
				if (j == needlelen)
					return ((char *)haystack + (i - needlelen));
			}
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		needlelen;

	needlelen = ft_strlen((char *)needle);
	if (needlelen == 0)
		return ((char *)haystack);
	return (ft_check(haystack, needle, len, needlelen));
}
