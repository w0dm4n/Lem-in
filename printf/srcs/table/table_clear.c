/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 18:53:59 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/01 23:10:56 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_table_clear(void ***atbl, void (*del)())
{
	size_t	i;

	if (atbl == NULL)
		return ;
	i = ft_table_size(*atbl);
	while (i > 0)
	{
		del((*atbl)[i - 1]);
		--i;
	}
	free(*atbl);
	*atbl = NULL;
}
