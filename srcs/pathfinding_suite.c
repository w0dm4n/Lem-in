/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_suite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:13:05 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/24 14:13:10 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_path		*cpy_path(t_path *path)
{
	t_room	*rooms;
	t_path	*n;

	rooms = path->rooms;
	if ((n = alloc_path(NULL)) == NULL)
		return (NULL);
	while (rooms)
	{
		append_path_room_list(copy_room(rooms), n);
		rooms = rooms->next;
	}
	return (n);
}

void		find_path_above(t_room *room, t_path *path,
		t_lemin *lemin, t_room *end_room)
{
	t_path		*cpy;
	t_pipe		*pipe;

	cpy = NULL;
	pipe = room->pipes;
	if (!in_path_list(room, path->rooms))
		append_path_room_list(copy_room(room), path);
	while (pipe)
	{
		if (!in_path_list(pipe->room, path->rooms))
		{
			cpy = cpy_path(path);
			append_path_room_list(copy_room(pipe->room), cpy);
			find_paths(pipe->room, cpy, lemin, end_room);
		}
		pipe = pipe->next;
	}
}

BOOL		find_path(t_lemin *lemin, t_room *room, t_path *path,
	t_room *end_room)
{
	t_room	*last;
	t_room	*rooms;

	last = NULL;
	rooms = lemin->rooms;
	while (rooms)
	{
		if ((last = last_from_path(path)) == NULL)
		{
			append_path_room_list(copy_room(room), path);
			find_paths(last_from_path(path), path, lemin, end_room);
			break ;
		}
		else if (rooms != room && rooms != end_room
				&& room_linked(rooms, last)
				&& !in_path_list(rooms, path->rooms))
		{
			append_path_room_list(copy_room(rooms), path);
			if (check_result(room, end_room, path, lemin))
				return (TRUE);
			find_paths(last_from_path(path), path, lemin, end_room);
		}
		rooms = rooms->next;
	}
	return (FALSE);
}
