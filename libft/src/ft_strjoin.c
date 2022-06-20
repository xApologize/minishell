/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:52:46 by jrossign          #+#    #+#             */
/*   Updated: 2022/03/03 11:10:37 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		s1len;
	int		s2len;
	int		i;
	char	*newstring;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	i = s1len;
	newstring = ft_calloc((s1len + s2len + 1), sizeof(char));
	if (!newstring)
		return (NULL);
	newstring = ft_memcpy(newstring, s1, s1len);
	while (i < s1len + s2len)
	{
		newstring[i] = s2[i - s1len];
		i++;
	}
	return (newstring);
}
