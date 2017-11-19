/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:52:18 by frmarinh          #+#    #+#             */
/*   Updated: 2015/05/24 16:12:50 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstd_clear(t_listd **alst, void (*del)(void*))
{
	t_listd		*tmp;

	if (!alst || !*alst)
		return ;
	while (*alst)
	{
		if (del)
			del((*alst)->data);
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
	}
}
