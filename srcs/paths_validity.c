/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 05:03:28 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/22 05:03:33 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_room		*get_last_path_room(t_path *path)
{
	t_room		*rooms;

	rooms = path->rooms;
	while (rooms->next)
		rooms = rooms->next;
	return (rooms);
}

BOOL		invalid_path(t_path *path, t_lemin *lemin)
{
	t_room		*rooms;
	t_room		*last;

	rooms = path->rooms;
	last = get_last_path_room(path);
	while (rooms)
	{
		if (rooms->next)
		{
			if (!room_linked(rooms, rooms->next))
				return (TRUE);
		}
		rooms = rooms->next;
	}
	if (last && room_linked(last, get_end_room(lemin)))
		return (FALSE);
	else
		return (TRUE);
}

void		check_paths_validity(t_path *paths, t_lemin *lemin)
{
	t_path		*p;

	p = paths;
	while (p)
	{
		if (invalid_path(p, lemin))
		{
			lemin->paths = remove_from_paths_list(p, paths);
			check_paths_validity(lemin->paths, lemin);
			break;
		}
		p = p->next;
	}
}
