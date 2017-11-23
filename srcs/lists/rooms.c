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

int			count_rooms(t_room *rooms)
{
	t_room		*r;
	int			count;

	count = 0;
	r = rooms;
	while (r)
	{
		count += 1;
		r = r->next;
	}
	return (count);
}

#define FN_1 void		print_rooms(t_room *rooms)
#define FN_2 { t_room	*p; p = rooms; while (p) {
#define FN_3 ft_printf("%s - ", p->name); p = p->next; } }
#define FUNC FN_1 FN_2 FN_3

FUNC;

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
		{
			ft_printf("The room %s is set multiple times"
			" on the map\n", room->name);
		}
	}
	else
		lemin->rooms = room;
}
