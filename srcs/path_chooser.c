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

t_path		*find_shortest_path(t_lemin *lemin)
{
	t_path		*paths;
	t_path		*chosen;
	int			smallest;
	int			path_rooms;

	smallest = 0;
	chosen = NULL;
	paths = lemin->paths;
	path_rooms = 0;
	while (paths)
	{
		path_rooms = count_rooms(paths->rooms);
		if (path_rooms < smallest || smallest == 0)
		{
			chosen = paths;
			smallest = path_rooms;
		}
		paths = paths->next;
	}
	return (chosen);
}

void		select_path(t_ant *ant, t_lemin *lemin)
{
	ant->following_path = find_shortest_path(lemin);
}
