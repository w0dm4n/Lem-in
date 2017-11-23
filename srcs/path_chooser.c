/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_chooser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:39:14 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/22 09:39:24 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		range_paths(t_lemin *lemin)
{
	t_path		*paths;
	t_path		*prev;
	t_path		*tmp;
	int			path_rooms;

	paths = lemin->paths;
	path_rooms = 0;
	prev = NULL;
	tmp = NULL;
	while (paths)
	{
		if (prev && count_rooms(paths->rooms) < count_rooms(prev->rooms))
		{
			switch_rooms(prev, paths);
			paths = lemin->paths;
		}
		prev = paths;
		paths = paths->next;
	}
}

BOOL		ant_on_room(char *room_name, t_lemin *lemin, t_ant *ant)
{
	t_ant		*ants;

	ants = lemin->ants;
	while (ants)
	{
		if (ants->id != ant->id &&
			!ft_strcmp(room_name, ants->current_room->name))
			return (TRUE);
		ants = ants->next;
	}
	return (FALSE);
}

int			get_first_ant_on_path(t_room *rooms, t_lemin *lemin, t_ant *ant)
{
	t_room		*r;
	int			count;

	r = rooms->next;
	count = 0;
	while (r)
	{
		count++;
		if (ant_on_room(r->name, lemin, ant))
			return (count);
		r = r->next;
	}
	return (-1);
}

t_path		*find_best_path(t_lemin *lemin, t_ant *ant)
{
	t_path		*chosen;
	int			first_path_rooms;
	t_path		*paths;
	int			pos_ant;
	int			current_pos_ant;

	first_path_rooms = count_rooms(lemin->paths->rooms);
	paths = lemin->paths;
	chosen = paths;
	pos_ant = 0;
	current_pos_ant = 0;
	while (paths)
	{
		current_pos_ant = get_first_ant_on_path(paths->rooms, lemin, ant);
		if (current_pos_ant > pos_ant || pos_ant == 0)
		{
			chosen = paths;
			pos_ant = current_pos_ant;
		}
		paths = paths->next;
	}
	return (chosen);
}

void		select_path(t_ant *ant, t_lemin *lemin)
{
	ant->following_path = find_best_path(lemin, ant);
	log_ant(ant, lemin);
}
