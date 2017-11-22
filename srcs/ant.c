/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 03:22:39 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/20 03:22:45 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void			get_ants_length(t_lemin *lemin, char *line)
{
	if (line[0] != COMMENT_DELIM)
	{
		if ((lemin->ants_length = ft_atoi(line)) <= 0)
		{
			ft_printf("Invalid number of ants.. %s\n", line);
			exit(-1);
		}
		else if (lemin->ants_length > MAX_ANTS)
		{
			ft_printf("Invalid number of ants.. (%d > %d) \n", lemin->ants_length,
				MAX_ANTS);
			exit(-1);
		}
	}
}

t_ant			*new_ant(int id, t_room *start_room)
{
	t_ant			*new_ant;

	if (!(new_ant = (t_ant*)malloc(sizeof(struct s_ant))))
		return (NULL);
	new_ant->id = id;
	new_ant->current_room = start_room;
	new_ant->next = NULL;
	new_ant->following_path = NULL;
	return (new_ant);
}

void			init_ants(t_lemin *lemin)
{
	int		i;
	t_room	*start_room;

	i = 0;
	if ((start_room = get_start_room(lemin)) != NULL)
	{
		while (i < lemin->ants_length)
			append_ants_list(new_ant(i++, start_room), lemin);
	}
}
