/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 23:38:45 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/19 23:41:55 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_lemin		*alloc_lemin(void)
{
	t_lemin		*lemin;

	if (!(lemin = (t_lemin*)malloc(sizeof(struct s_lemin))))
		return (NULL);
	lemin->ants_length = 0;
	lemin->waiting_for_end_room = FALSE;
	lemin->waiting_for_start_room = FALSE;
	lemin->rooms = NULL;
	lemin->ants = NULL;
	return (lemin);
}
