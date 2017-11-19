/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_rmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:58:16 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/01 19:59:14 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_table_rmap(void **tbl, void (*map)())
{
	size_t	i;

	if (tbl == NULL)
		return ;
	i = ft_table_size(tbl);
	while (i > 0)
	{
		map(tbl[i - 1]);
		--i;
	}
}
