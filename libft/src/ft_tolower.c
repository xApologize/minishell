/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:34:37 by jrossign          #+#    #+#             */
/*   Updated: 2021/09/18 17:34:50 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int character)
{
	if (character >= 65 && character <= 90)
		return (character + 32);
	return (character);
}
