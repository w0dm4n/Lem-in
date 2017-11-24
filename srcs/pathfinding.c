/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 00:17:33 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/21 00:17:42 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_room		*last_from_path(t_path *path)
{
	t_room		*rooms;

	rooms = path->rooms;
	if (!rooms)
		return (NULL);
	while (rooms->next)
		rooms = rooms->next;
	return (rooms);
}

BOOL		in_path_list(t_room *room, t_room *rooms)
{
	t_room	*p;

	p = rooms;
	if (p)
	{
		while (p)
		{
			if (!ft_strcmp(room->name, p->name))
				return (TRUE);
			p = p->next;
		}
	}
	return (FALSE);
}

void		reset_path_list(t_path *path, t_lemin *lemin)
{
	t_room		*rooms;

	rooms = path->rooms;
	while (rooms)
	{
		free(rooms);
		rooms = rooms->next;
	}
	path->rooms = NULL;
}

BOOL		check_result(t_room *room, t_room *end_room, t_path *path,
	t_lemin *lemin)
{
	t_path		*new_path;

	new_path = NULL;
	if (count_paths(lemin->paths) > MAX_PATHS)
		return (TRUE);
	if (room_linked(room, end_room))
	{
		if ((new_path = cpy_path(path)) != NULL)
		{
			append_paths_list(new_path, lemin->paths);
			return (TRUE);
		}
	}
	return (FALSE);
}

BOOL		find_paths(t_room *room, t_path *path,
		t_lemin *lemin, t_room *end_room)
{
	t_room		*last;
	t_room		*rooms;

	last = NULL;
	rooms = NULL;
	if (check_result(room, end_room, path, lemin))
		return (TRUE);
	if (count_pipes(room) > 2)
		find_path_above(room, path, lemin, end_room);
	else
	{
		if (find_path(lemin, room, path, end_room))
			return (TRUE);
	}
	return (FALSE);
}
