/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 00:01:33 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/20 00:01:37 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		parse_room(t_lemin *lemin, char *line)
{
	char		**data;
	t_room		*room;

	room = NULL;
	if ((data = ft_strsplit(line, ROOM_DELIM)) != NULL)
	{
		if (ft_lenarray((void**)data) == 3)
			room = new_room(data[0], ft_atoi(data[1]), ft_atoi(data[2]), lemin);
		else if (ft_lenarray((void**)data) == 1)
			room = new_room(data[0], 0, 0, lemin);
		if (room != NULL)
			append_room_list(room, lemin);
		ft_free_array((void**)data);
	}
}

void		parse_pipe(t_lemin *lemin, char *line)
{
	char	**data;
	t_room	*first;
	t_room	*second;

	first = NULL;
	second = NULL;
	if ((data = ft_strsplit(line, PIPE_DELIM)) != NULL)
	{
		if (ft_lenarray((void**)data) == 2)
		{
			link_rooms(get_room_by_name(data[0], lemin),
				get_room_by_name(data[1], lemin), lemin);
		}
		ft_free_array((void**)data);
	}
}
