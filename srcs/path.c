/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:42:18 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/21 01:42:22 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		switch_rooms(t_path *larger, t_path *smaller)
{
	t_room	*tmp;

	tmp = larger->rooms;
	larger->rooms = smaller->rooms;
	smaller->rooms = tmp;
}

t_path		*alloc_path(t_room *room)
{
	t_path		*path;

	if (!(path = (t_path*)malloc(sizeof(struct s_path))))
		return (NULL);
	path->rooms = room;
	path->valid = FALSE;
	path->next = NULL;
	return (path);
}
