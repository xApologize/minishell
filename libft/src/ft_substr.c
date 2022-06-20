/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:58:58 by jrossign          #+#    #+#             */
/*   Updated: 2022/03/03 11:10:23 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	slen;
	char			*newstring;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen((char *)s);
	if (len > slen)
		newstring = ft_calloc((slen + 1), sizeof(char));
	else
		newstring = ft_calloc((len + 1), sizeof(char));
	if (!newstring)
		return (NULL);
	if (start >= slen)
		return (newstring);
	while (i < len && s[i])
	{
		newstring[i] = s[start + i];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
