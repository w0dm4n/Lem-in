/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:54:54 by frmarinh          #+#    #+#             */
/*   Updated: 2016/04/11 12:40:27 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_lstd_del(t_listd **alst, void (*del)())
{
	t_listd		*next;
	t_listd		*prev;

	if (!alst || !*alst)
		return ;
	if ((*alst)->prev == NULL)
		return (ft_lstd_pop_front(alst, del));
	next = (*alst)->next;
	prev = (*alst)->prev;
	if ((*alst)->data && del)
		del((*alst)->data);
	if (next)
		next->prev = prev;
	if (prev)
		prev->next = next;
	free(*alst);
	*alst = next;
}
