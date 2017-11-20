/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 02:34:35 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/20 02:34:39 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void			free_room_pipes(t_room *room)
{
	t_pipe	*pipes;

	pipes = room->pipes;
	while (pipes)
	{
		free(pipes);
		pipes = pipes->next;
	}
}

void			free_ants(t_lemin *lemin)
{
	t_ant		*ants;

	ants = lemin->ants;
	while (ants)
	{
		free(ants);
		ants = ants->next;
	}
}

void			free_lemin(t_lemin *lemin)
{
	t_room		*rooms;

	rooms = lemin->rooms;
	while (rooms)
	{
		free_room_pipes(rooms);
		free(rooms->name);
		free(rooms);
		rooms = rooms->next;
	}
	free_ants(lemin);
	free(lemin);
}
