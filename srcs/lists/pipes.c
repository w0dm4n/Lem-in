/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 02:17:36 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/20 02:17:41 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		append_room_pipe(t_pipe *pipe, t_room *room)
{
	t_pipe		*pipes;

	pipes = room->pipes;
	if (pipe != NULL)
	{
		if (pipes != NULL)
		{
			while (pipes->next)
				pipes = pipes->next;
			pipes->next = pipe;
		}
		else
			room->pipes = pipe;
	}
}

BOOL		room_linked(t_room *first, t_room *second)
{
	t_pipe	*pipes;
	t_room	*tmp_room;

	tmp_room = NULL;
	pipes = first->pipes;
	while (pipes)
	{
		tmp_room = (t_room*)pipes->room;
		if (!ft_strcmp(tmp_room->name, second->name))
			return (TRUE);
		pipes = pipes->next;
	}
	return (FALSE);
}
