/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:08:17 by jrossign          #+#    #+#             */
/*   Updated: 2022/03/03 11:09:56 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	int		s1len;
	int		i;
	char	*newstring;

	s1len = ft_strlen((char *)s1) + 1;
	i = 0;
	newstring = malloc(s1len * sizeof(char));
	if (!newstring)
		return (NULL);
	while (s1[i])
	{
		newstring[i] = s1[i];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
