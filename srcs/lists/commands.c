/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:20:34 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/23 10:20:38 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void			append_commands_list(t_command *command, t_lemin *lemin)
{
	t_command	*c;

	if (!command)
		return ;
	c = lemin->commands;
	if (lemin->commands)
	{
		while (c->next)
			c = c->next;
		c->next = command;
	}
	else
		lemin->commands = command;
}
