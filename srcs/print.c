/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:10:40 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/23 10:10:45 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static void			list_commands(t_command *commands)
{
	t_command	*c;

	ft_printf("Commands:\n");
	c = commands;
	while (c)
	{
		ft_printf("- {cyan}%s{white}\n", c->name);
		c = c->next;
	}
}

static void			list_comments(t_comment *comments)
{
	t_comment	*c;

	c = comments;
	ft_printf("Comments:\n");
	while (c)
	{
		ft_printf("- {green}%s{white}\n", c->name);
		c = c->next;
	}
}

void				print_commands_and_comments(t_lemin *lemin)
{
	ft_printf("GIVEN MAP:\n {light magenta}%s{white}\n\n", lemin->map_raw);
	list_commands(lemin->commands);
	if (count_comments(lemin->comments) > 0)
		list_comments(lemin->comments);
}
