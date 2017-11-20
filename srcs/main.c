/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:24:05 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/19 22:24:37 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static BOOL		check_state(t_lemin *lemin, char *line)
{
	BOOL	res;

	res = FALSE;
	if (!ft_strcmp(line, START_ROOM))
	{
		lemin->waiting_for_start_room = TRUE;
		res = TRUE;
	}
	else if (!ft_strcmp(line, END_ROOM))
	{
		lemin->waiting_for_end_room = TRUE;
		res = TRUE;
	}
	return (res);
}

static void		parse_entry(t_lemin *lemin)
{
	char	*line;

	line = NULL;
	while ((get_next_line(STDIN_FILENO, &line)) > 0)
	{
		if (line != NULL && ft_strlen(line) > 0)
		{
			if (lemin->ants_length > 0)
			{
				if (!check_state(lemin, line))
				{
					if (line[0] != COMMENT_DELIM)
					{
						if (ft_strchr(line, ROOM_DELIM) != NULL)
							parse_room(lemin, line);
						else if (ft_strchr(line, PIPE_DELIM) != NULL)
							parse_pipe(lemin, line);
					}
				}
			}
			else
				get_ants_length(lemin, line);
			free(line);
		}
	}
}

int				main(int argc, char **argv)
{
	t_lemin		*lemin;

	if (!(lemin = alloc_lemin()))
		return (-1);
	parse_entry(lemin);
	init_ants(lemin);
	// ft_printf("%s\n", lemin->ants->current_room->name);
	// t_room		*rooms = lemin->rooms;
	// while (rooms)
	// {
	// 	printf("Name: %s\n", rooms->name);
	// 	rooms = rooms->next;
	// }
	// if (room_linked(get_room_by_name("Nm_otool", lemin), get_room_by_name("IRC", lemin)))
	// {
	// 	ft_printf("Room linked !\n");
	// }
	free_lemin(lemin);
	return (0);
}
