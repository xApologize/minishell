/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:30:10 by jrossign          #+#    #+#             */
/*   Updated: 2022/07/11 15:30:11 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Unset without any options. Adding option triggers an error message.
// bash: unset: (option used): invalid option
void	handle_unset(char **opt, char **envp_copy)
{
	access(envp_copy[0], F_OK);
	printf("%s\n", opt[0]);
}
