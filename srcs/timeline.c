/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 00:23:42 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/21 00:23:51 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

BOOL			ant_in_room(char *room_name, t_lemin *lemin)
{
	t_ant	*ants;

	ants = lemin->ants;
	while (ants)
	{
		if (!ft_strcmp(ants->current_room->name, room_name))
			return (TRUE);
		ants = ants->next;
	}
	return (FALSE);
}

BOOL			ants_not_on_end_room(t_lemin *lemin)
{
	t_ant	*ants;

	ants = lemin->ants;
	while (ants)
	{
		if (!ants->in_end_room)
			return (TRUE);
		ants = ants->next;
	}
	return (FALSE);
}

t_room			*get_next_ant_room(t_ant *ant)
{
	t_room		*rooms;

	if (!ant->following_path)
		return (NULL);
	rooms = ant->following_path->rooms;
	while (rooms)
	{
		if (!ft_strcmp(rooms->name, ant->current_room->name))
			return (rooms->next);
		rooms = rooms->next;
	}
	return (NULL);
}

BOOL			is_ant_at_end(t_ant *ant, t_room *end)
{
	if (room_linked(ant->current_room, end))
	{
		ft_printf("{yellow}L{red}%d{white}-{blue}%s{white} ",
			ant->id, end->name);
		ant->current_room = end;
		ant->in_end_room = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

void			start_timeline(t_lemin *lemin)
{
	t_ant	*ants;

	ft_printf("\nAnts path: \n");
	ants = NULL;
	while (ants_not_on_end_room(lemin))
	{
		ants = lemin->ants;
		while (ants)
		{
			if (!ants->in_end_room)
			{
				if (!is_ant_at_end(ants, get_end_room(lemin)))
				{
					if (ants->following_path == NULL)
						select_path(ants, lemin);
					move_ant(ants, get_next_ant_room(ants), lemin);
				}
			}
			ants = ants->next;
		}
		ft_printf("\n");
	}
}
