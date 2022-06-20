/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:16:01 by jrossign          #+#    #+#             */
/*   Updated: 2022/03/03 11:11:14 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*string_getter_neg(char *str, long n, int counter)
{
	while (counter > 0)
	{
		str[counter--] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}

static char	*string_getter(char *str, long n, int counter)
{
	while (counter >= 0)
	{
		str[counter--] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}

static int	char_size(long long n)
{
	long	i;
	int		j;

	i = 1;
	j = 0;
	if (n == 0)
		return (1);
	while (n % i != n)
	{
		i *= 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;

	nb = n;
	if (n >= 0)
		str = ft_calloc(char_size(nb) + 1, sizeof(char));
	else
	{
		str = ft_calloc(char_size(nb) + 2, sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '-';
		return (string_getter_neg(str, nb * -1, char_size(nb)));
	}
	if (!str)
		return (NULL);
	return (string_getter(str, nb, char_size(nb) - 1));
}
