/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:32:27 by jrossign          #+#    #+#             */
/*   Updated: 2021/09/18 17:32:28 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int character)
{
	if (character >= 32 && character <= 126)
		return (1);
	return (0);
}
