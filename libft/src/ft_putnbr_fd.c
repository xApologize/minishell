/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:32:43 by jrossign          #+#    #+#             */
/*   Updated: 2022/03/03 11:13:29 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	n2;

	n2 = n;
	if (n2 < 0)
	{
		ft_putchar_fd('-', fd);
		n2 *= -1;
	}
	if (n2 > 9)
	{
		ft_putnbr_fd(n2 / 10, fd);
		ft_putchar_fd(n2 % 10 + 48, fd);
	}
	else
		ft_putchar_fd(n2 + 48, fd);
}
