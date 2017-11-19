/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_pop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 17:37:59 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/01 23:30:45 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_table_pop_back(void ***atbl, void (*del)())
{
	size_t	i;

	if (atbl == NULL || *atbl == NULL)
		return ;
	i = 0;
	while ((*atbl)[i] && (*atbl)[i + 1])
		++i;
	if ((*atbl)[i] != NULL && del != NULL)
		del((*atbl)[i]);
	if (i == 0)
	{
		free(*atbl);
		*atbl = NULL;
	}
	else
		(*atbl)[i] = NULL;
}
