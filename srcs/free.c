/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 02:34:35 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/20 02:34:39 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void			free_room_pipes(t_room *room)
{
	t_pipe	*pipes;

	pipes = room->pipes;
	while (pipes)
	{
		free(pipes);
		pipes = pipes->next;
	}
}

void			free_ants(t_lemin *lemin)
{
	t_ant		*ants;

	ants = lemin->ants;
	while (ants)
	{
		free(ants);
		ants = ants->next;
	}
}

void			free_lemin(t_lemin *lemin)
{
	t_room		*rooms;
	t_command	*commands;
	t_comment	*comments;

	commands = lemin->commands;
	comments = lemin->comments;
	rooms = lemin->rooms;
	while (rooms)
	{
		free_room_pipes(rooms);
		free(rooms->name);
		free(rooms);
		rooms = rooms->next;
	}
	_(free_ants(lemin), free(lemin));
	while (commands)
	{
		_(ft_strdel(&commands->name), free(commands));
		commands = commands->next;
	}
	while (comments)
	{
		_(ft_strdel(&comments->name), free(comments));
		comments = comments->next;
	}
}

void			free_rooms(t_room *base)
{
	t_room	*r;

	r = base;
	while (r)
	{
		free(r);
		r = r->next;
	}
}

void			free_path(t_path *base)
{
	free_rooms(base->rooms);
	free(base);
}
