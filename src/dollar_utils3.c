/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:17:07 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/18 13:17:09 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

void	quote_on(bool *quote, int *i)
{
	*quote = true;
	*i += 1;
}

void	d_quote_on(bool *d_quote, int *i)
{
	*d_quote = true;
	*i += 1;
}

char	*met_quote(char *new_line, char **line, bool *d_quote)
{
	*d_quote = true;
	new_line = charjoinfree(new_line, **line);
	*line += 1;
	return (new_line);
}
