/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 01:27:56 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/20 01:28:02 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_room		*get_room_by_name(char *name, t_lemin *lemin)
{
	t_room		*rooms;

	rooms = lemin->rooms;
	while (rooms)
	{
		if (!ft_strcmp(rooms->name, name))
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

t_room		*get_start_room(t_lemin *lemin)
{
	t_room		*rooms;

	rooms = lemin->rooms;
	while (rooms)
	{
		if (rooms->start_room)
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

t_room		*get_end_room(t_lemin *lemin)
{
	t_room		*rooms;

	rooms = lemin->rooms;
	while (rooms)
	{
		if (rooms->end_room)
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

void		append_room_list(t_room *room, t_lemin *lemin)
{
	t_room		*rooms;

	rooms = lemin->rooms;
	if (lemin->rooms)
	{
		if (get_room_by_name(room->name, lemin) == NULL)
		{
			while (rooms->next)
				rooms = rooms->next;
			rooms->next = room;
		}
		else
			ft_printf("The room %s is set multiple times"
			" on the map\n", room->name);
	}
	else
		lemin->rooms = room;
}
