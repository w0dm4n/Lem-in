/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 03:30:42 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/20 03:30:46 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void			append_ants_list(t_ant *new_ant, t_lemin *lemin)
{
	t_ant		*ants;

	ants = lemin->ants;
	if (new_ant)
	{
		if (lemin->ants)
		{
			while (ants->next)
				ants = ants->next;
			ants->next = new_ant;
		}
		else
			lemin->ants = new_ant;
	}
}
