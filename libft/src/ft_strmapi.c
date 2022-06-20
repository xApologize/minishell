/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:45:23 by jrossign          #+#    #+#             */
/*   Updated: 2022/03/03 11:11:29 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*newstring;

	if (!s)
		return (NULL);
	newstring = ft_strdup((char *)s);
	if (!newstring)
		return (NULL);
	i = 0;
	while (newstring[i])
	{
		newstring[i] = f(i, newstring[i]);
		i++;
	}
	return (newstring);
}
