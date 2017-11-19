/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtable_push_at_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:49:58 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/01 19:50:58 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtable_push_at_index(char ***atbl, void *new,
		size_t index)
{
	ft_table_push_at_index((void ***)atbl, new, index);
}
