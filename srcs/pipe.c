/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 00:09:38 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/20 00:09:43 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_pipe		*new_pipe(t_room *linked)
{
	t_pipe		*pipe;

	pipe = NULL;
	if (!(pipe = (t_pipe*)malloc(sizeof(struct s_pipe))))
		return (NULL);
	pipe->room = (void*)linked;
	pipe->next = NULL;
	return (pipe);
}

void		link_rooms(t_room *first, t_room *second, t_lemin *lemin)
{
	if (first != NULL && second != NULL)
	{
		if (room_linked(first, second) == FALSE)
		{
			append_room_pipe(new_pipe(second), first);
			append_room_pipe(new_pipe(first), second);
		}
	}
}

int			count_pipes(t_room *room)
{
	t_pipe	*pipes;
	int		count;

	count = 0;
	pipes = room->pipes;
	while (pipes)
	{
		count += 1;
		pipes = pipes->next;
	}
	return (count);
}
