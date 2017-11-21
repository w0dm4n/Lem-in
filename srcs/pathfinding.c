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

void		append_path_list(t_room *room, t_path *path)
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

void		print_list(t_room *rooms)
{
	t_room *p = rooms;
	while (p)
	{
		ft_printf("%s - ", p->name);
		p = p->next;
	}
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
	t_room	*rooms = path->rooms;
	t_path *n = malloc(sizeof(struct s_path));
	n->rooms = NULL;
	n->valid = FALSE;
	while (rooms)
	{
		append_path_list(copy_room(rooms), n);
		rooms = rooms->next;
	}
	return (n);
}

BOOL		check_result(t_room *room, t_room *end_room, t_path *path)
{
	if (room_linked(room, end_room))
	{
		print_list(path->rooms);
		ft_printf("\n");
		return (TRUE);
	}
	return (FALSE);
}

BOOL		find_path(t_room *room, t_path *path, t_lemin *lemin, t_room *end_room)
{
	if (check_result(room, end_room, path))
		return (TRUE);
	t_pipe *pipe = room->pipes;
	if (count_pipes(room) > 2)
	{
		if (!in_path_list(room, path->rooms))
			append_path_list(copy_room(room), path);
		while (pipe)
		{
			if (!in_path_list(pipe->room, path->rooms))
			{
				t_path *cpy = cpy_path(path);
				append_path_list(copy_room(pipe->room), cpy);
				find_path(pipe->room, cpy, lemin, end_room);
			}
			pipe = pipe->next;
		}
	}
	else
	{
		t_room *rooms = lemin->rooms;
		while (rooms)
		{
			if (rooms != room && rooms != end_room
				 && room_linked(rooms, room) && !in_path_list(rooms, path->rooms))
			{
				append_path_list(copy_room(rooms), path);
				if (check_result(room, end_room, path))
					return (TRUE);
				find_path(last_from_path(path), path, lemin, end_room);
			}
			rooms = rooms->next;
		}
	}
}
