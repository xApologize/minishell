/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:19:21 by jrossign          #+#    #+#             */
/*   Updated: 2022/03/03 11:08:00 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	strlen;

	strlen = ft_strlen((char *)s);
	while (strlen >= 0)
	{
		if (s[strlen] == (char)c)
			return ((char *)s + strlen);
		strlen--;
	}
	return (NULL);
}
