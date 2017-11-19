/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_push_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 17:24:29 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/01 18:30:13 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_table_push_back(void ***atbl, void *new)
{
	size_t	i;
	void	**tbl_new;

	if (atbl == NULL || *atbl == NULL)
		return (ft_table_new(atbl, new));
	tbl_new = (void **)malloc((ft_table_size(*atbl) + 2) * sizeof(void *));
	if (tbl_new == NULL)
		return ;
	i = 0;
	while ((*atbl)[i])
	{
		tbl_new[i] = (*atbl)[i];
		++i;
	}
	tbl_new[i] = new;
	tbl_new[i + 1] = NULL;
	free(*atbl);
	*atbl = tbl_new;
}
