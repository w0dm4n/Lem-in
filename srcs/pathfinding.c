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

void		append_path_room_list(t_room *room, t_path *path)
{
	t_room		*rooms;

	rooms = path->rooms;
	if (path->rooms)
	{
		while (rooms->next)
			rooms = rooms->next;
		rooms->next = room;
	}
	else
		path->rooms = room;
}

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
	t_room *p = rooms;
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

BOOL		check_result(t_room *room, t_room *end_room, t_path *path, t_lemin *lemin)
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

BOOL		find_paths(t_room *room, t_path *path, t_lemin *lemin, t_room *end_room)
{
	t_room		*last;

	last = NULL;
	if (check_result(room, end_room, path, lemin))
		return (TRUE);
	t_pipe *pipe = room->pipes;
	if (count_pipes(room) > 2)
	{
		if (!in_path_list(room, path->rooms))
			append_path_room_list(copy_room(room), path);
		while (pipe)
		{
			if (!in_path_list(pipe->room, path->rooms))
			{
				t_path *cpy = cpy_path(path);
				append_path_room_list(copy_room(pipe->room), cpy);
				find_paths(pipe->room, cpy, lemin, end_room);
			}
			pipe = pipe->next;
		}
	}
	else
	{
		t_room *rooms = lemin->rooms;
		while (rooms)
		{
			if ((last = last_from_path(path)) == NULL)
			{
				append_path_room_list(copy_room(room), path);
				find_paths(last_from_path(path), path, lemin, end_room);
				break;
			}
			else if (rooms != room && rooms != end_room
				 && room_linked(rooms, last) && !in_path_list(rooms, path->rooms))
			{
				append_path_room_list(copy_room(rooms), path);
				if (check_result(room, end_room, path, lemin))
					return (TRUE);
				find_paths(last_from_path(path), path, lemin, end_room);
			}
			rooms = rooms->next;
		}
	}
	return (FALSE);
}
