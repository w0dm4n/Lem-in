/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_rmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 14:27:15 by frmarinh          #+#    #+#             */
/*   Updated: 2015/05/24 15:42:07 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_rmap(t_listd **alst, void (*map)(void*))
{
	t_listd		*scan;

	if (!alst || !*alst)
		return ;
	scan = ft_lstd_back(*alst);
	while (scan)
	{
		map(scan->data);
		scan = scan->prev;
	}
}
