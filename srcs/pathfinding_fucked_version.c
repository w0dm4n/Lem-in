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

void		init_possible_path(t_path *path, t_room *start_room)
{
	path->rooms = copy_room(start_room);
	path->valid = FALSE;
}

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

void		print_list(t_room *rooms)
{
	t_room *p = rooms;
	while (p)
	{
		ft_printf("%s ", p->name);
		p = p->next;
	}
	ft_printf("\n");
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
	path->rooms = copy_room(get_start_room(lemin));
}

t_forbidden		*new_forbidden(char *name)
{
	t_forbidden *new_forb;

	if (!(new_forb = malloc(sizeof(struct s_forbidden))))
		return (NULL);
	new_forb->room_name = ft_strdup(name);
	new_forb->next = NULL;
	return (new_forb);
}

t_forbidden		*append_forbidden_list(t_forbidden *forbidden, t_forbidden *forbiddens)
{
	t_forbidden		*forb;

	if (!forbidden)
		return (NULL);
	forb = forbiddens;
	if (forbiddens)
	{
		while (forb->next)
			forb = forb->next;
		forb->next = forbidden;
		return (forbiddens);
	}
	else
		return (forbidden);
}

BOOL		in_forbidden_list(t_forbidden *forbidden, char *name)
{
	t_forbidden *forb;

	if (forbidden == NULL)
		return (FALSE);
	forb = forbidden;
	while (forb)
	{
		if (!ft_strcmp(forb->room_name, name))
			return (TRUE);
		forb = forb->next;
	}
	return (FALSE);
}

t_forbidden		*close_next_room(t_room *room, t_room *base_rooms, t_forbidden *forbiddens, t_path *path)
{
	t_room		*rooms;

	rooms = base_rooms;
	while (rooms)
	{
		if (room_linked(rooms, room) && !in_forbidden_list(forbiddens, rooms->name) && !in_path_list(rooms, path->rooms))
		{
			append_path_list(copy_room(rooms), path);
			ft_printf("Forbidden: %s\n", rooms->name);
			forbiddens = append_forbidden_list(new_forbidden(rooms->name), forbiddens);
			break ;
		}
		rooms = rooms->next;
	}
	return (forbiddens);
}

t_forbidden		*remove_from_forbidden_list(char *name, t_forbidden *forbiddens)
{
	t_forbidden	*forb;
	t_forbidden	*prev;

	forb = forbiddens;
	prev = NULL;
	while (forb)
	{
		if (!ft_strcmp(forb->room_name, name))
		{
			ft_printf("%s removed from forbidden list\n", forb->room_name);
			if (prev)
			{
				free(forb);
				prev->next = forb->next;
			}
			else
			{
				free(forb);
				return (forb->next);
			}

			break ;
		}
		prev = forb;
		forb = forb->next;
	}
	return (forbiddens);
}

t_forbidden		*open_next_room(t_room *room, t_room *base_rooms, t_forbidden *forbiddens, t_path *path)
{
	t_room		*rooms;

	rooms = base_rooms;
	while (rooms)
	{
		if (room_linked(rooms, room) && in_forbidden_list(forbiddens, rooms->name))
		{
			forbiddens = remove_from_forbidden_list(rooms->name, forbiddens);
			// exit(0);
		}
		rooms = rooms->next;
	}
	return (forbiddens);
}

void		find_path(t_path *path, t_room *end_room, t_lemin *lemin)
{
	t_room		*rooms;
	BOOL		result;
	t_forbidden	*forbiddens;
	t_room		*path_end;

	rooms = lemin->rooms;
	result = FALSE;
	forbiddens = NULL;
	path_end = NULL;
	while (!result)
	{
		while (rooms)
		{
			if (!rooms->start_room && !in_path_list(rooms, path->rooms) &&
				!in_forbidden_list(forbiddens, rooms->name))
			{
				if (room_linked(rooms, last_from_path(path)))
				{
					append_path_list(copy_room(rooms), path);
					print_list(path->rooms);
					if (room_linked(rooms, end_room))
					{
						ft_printf("END FOUND !\n");
					}
					if (count_pipes(rooms) > 2)
					{
						forbiddens = close_next_room(rooms, lemin->rooms, forbiddens, path);
						//forbiddens = append_forbidden_list(new_forbidden(rooms->name), forbiddens);
						// ft_printf("%s\n", rooms->name);
					}
					rooms = lemin->rooms;
				}
			}
			rooms = rooms->next;
		}
		t_room *last_from_current = last_from_path(path);
		if (path_end != NULL && last_from_current != NULL &&
			!ft_strcmp(path_end->name, last_from_current->name))
		{
			forbiddens = open_next_room(path_end, lemin->rooms, forbiddens, path);
			ft_printf("STUCK AT %s\n", path_end->name);
		}
		if (path_end) {
			free(path_end);
		}
		path_end = copy_room(last_from_path(path));
		reset_path_list(path, lemin);
		rooms = lemin->rooms;
	}
}

BOOL		find_paths(t_path *paths, t_lemin *lemin)
{
	int		i;

	i = 0;
	while (i < MAX_PATHS)
	{
		init_possible_path(&paths[i], get_start_room(lemin));
		find_path(&paths[i], get_end_room(lemin), lemin);
		// t_room *rooms = paths[i].rooms;
		// while (rooms)
		// {
		// 	ft_printf("%s-", rooms->name);
		// 	rooms = rooms->next;
		// }
		// ft_printf("\n");
		break;
		i++;
	}
	return (FALSE);
}