/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 21:22:15 by frmarinh          #+#    #+#             */
/*   Updated: 2015/05/23 19:13:59 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstd_new(t_listd **alst, void *new)
{
	t_listd		*tmp;

	if ((tmp = (t_listd *)malloc(sizeof(t_listd))) != NULL)
	{
		tmp->data = new;
		tmp->prev = NULL;
		tmp->next = NULL;
		*alst = tmp;
	}
}
