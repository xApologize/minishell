/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:27:57 by jrossign          #+#    #+#             */
/*   Updated: 2022/03/03 11:08:31 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	void	*ret;
	int		i;

	i = 0;
	while ((unsigned)i < n)
	{
		if (((char *)str)[i] == (char)c)
		{
			ret = ((char *)str + i);
			return (ret);
		}
		i++;
	}
	return (0);
}
