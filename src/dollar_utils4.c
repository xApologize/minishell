/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:46:34 by yst-laur          #+#    #+#             */
/*   Updated: 2022/10/21 11:11:47 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

char	*set_quotes_on(char	*new_line, char **line, bool *quote, bool *d_quote)
{
	if (**line == '"' && *d_quote == false)
		return (met_d_quote(new_line, line, d_quote));
	if (**line == '\'' && *d_quote == false && *quote == false)
		return (met_quote(new_line, line, quote));
	return (new_line);
}

void	set_quotes_off(char line, bool *quote, bool *d_quote)
{
	if (line == '"' && *d_quote == true)
		*d_quote = false;
	if (line == '\'' && *quote == true && *d_quote == false)
		*quote = false;
}

char	*set_quotes_off_free(char *new_line, char **line,
		bool *quote, bool *d_quote)
{
	new_line = charjoinfree(new_line, **line);
	set_quotes_off(**line, quote, d_quote);
	*line += 1;
	return (new_line);
}
