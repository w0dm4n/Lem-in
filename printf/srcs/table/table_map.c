/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:56:54 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/01 19:58:07 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_table_map(void **tbl, void (*map)())
{
	size_t	i;

	if (tbl == NULL)
		return ;
	i = 0;
	while (tbl[i])
	{
		map(tbl[i]);
		++i;
	}
}
