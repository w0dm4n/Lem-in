/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 00:09:31 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/20 00:09:35 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static BOOL			set_start_room(t_lemin *lemin)
{
	lemin->waiting_for_start_room = FALSE;
	return (TRUE);
}

static BOOL			set_end_room(t_lemin *lemin)
{
	lemin->waiting_for_end_room = FALSE;
	return (TRUE);
}

t_room			*new_room(char *name, int x, int y, t_lemin *lemin)
{
	t_room		*room;

	if (!(room = (t_room*)malloc(sizeof(struct s_room))))
		return (NULL);
	room->name = ft_strdup(name);
	room->x = x;
	room->y = y;
	room->start_room = (lemin->waiting_for_start_room) ? set_start_room(lemin) : FALSE;
	room->end_room = (lemin->waiting_for_end_room) ? set_end_room(lemin) : FALSE;
	room->next = NULL;
	room->pipes = NULL;
	return (room);
}
