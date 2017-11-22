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

void			move_ant(t_ant *ant, t_lemin *lemin)
{
	ft_printf("Hello ant %d\n", ant->id);
}

BOOL			ants_not_on_end_room(t_lemin *lemin)
{
	t_ant	*ants;
	t_room	*room;

	ants = lemin->ants;
	room = NULL;
	while (ants)
	{
		if ((room = ants->current_room) != NULL)
		{
			if (!room->end_room)
				return (TRUE);
		}
		else
			return (FALSE);
		ants = ants->next;
	}
	return (FALSE);
}

void			start_timeline(t_lemin *lemin)
{
	t_ant	*ants;

	ants = NULL;
	while (ants_not_on_end_room(lemin))
	{
		ants = lemin->ants;
		while (ants)
		{
			ft_printf("(%d) moving !\n", ants->id);
			ants = ants->next;
		}
	}
}
