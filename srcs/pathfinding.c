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

BOOL		find_path(t_room *room, t_path *path, t_lemin *lemin, t_room *end_room)
{
	t_room		*rooms;
	t_room		*last;

	rooms = lemin->rooms;
	last = (path->rooms) ? last_from_path(path) : NULL;
	while (rooms)
	{
		last = (path->rooms) ? last_from_path(path) : NULL;
		if (last && rooms == last)
		{
			rooms = rooms->next;
			continue;
		}
		if (rooms != end_room && rooms != get_start_room(lemin))
		{
			if ((rooms != room && room_linked(rooms, last) && !in_path_list(rooms, path->rooms)) || last == NULL)
			{
				print_list(path->rooms);
				ft_printf("\n");
				append_path_list(copy_room(rooms), path);
				if (room_linked(rooms, end_room))
				{
					t_room *start = get_start_room(lemin);
					ft_printf(" %s - ", start->name);
					print_list(path->rooms);
					ft_printf(" %s\n", end_room->name);
					return (TRUE);
				}
				if (count_pipes(rooms) > 2)
				{
					t_pipe *pipes = rooms->pipes;
					while (pipes)
					{
						find_path(pipes->room, cpy_path(path), lemin, end_room);
						pipes = pipes->next;
					}
				}
				else
					find_path(last_from_path(path), path, lemin, end_room);
			}
		}
		rooms = rooms->next;
	}
}
