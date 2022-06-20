/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:33:11 by jrossign          #+#    #+#             */
/*   Updated: 2022/03/03 11:09:34 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*c;
	size_t			malloc_size;
	unsigned int	i;

	malloc_size = count * size;
	c = malloc(malloc_size);
	i = 0;
	if (c == NULL)
		return (NULL);
	while (i < malloc_size)
	{
		c[i] = 0;
		i++;
	}
	return ((void *)c);
}
