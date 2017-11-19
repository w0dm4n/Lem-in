/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 14:27:15 by frmarinh          #+#    #+#             */
/*   Updated: 2015/07/19 07:35:05 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_map(t_listd **alst, void (*map)())
{
	t_listd		*scan;

	if (!alst || !*alst)
		return ;
	scan = ft_lstd_front(*alst);
	while (scan)
	{
		map(scan->data);
		scan = scan->next;
	}
}
