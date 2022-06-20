/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:12:19 by jrossign          #+#    #+#             */
/*   Updated: 2022/06/01 15:06:32 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(const char *s1, const char set)
{
	int		i;
	int		j;
	int		s1len;

	if (!s1 || !set)
		return (NULL);
	s1len = ft_strlen((char *)s1);
	i = 0;
	while (i < s1len && s1[i] == set)
		i++;
	j = s1len - 1;
	while (j > i && s1[j] == set)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
