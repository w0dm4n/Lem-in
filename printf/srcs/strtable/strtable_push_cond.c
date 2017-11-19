/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtable_push_cond.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:51:12 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/01 19:52:33 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtable_push_cond(char ***atbl, void *new,
		int (*cond)())
{
	ft_table_push_cond((void ***)atbl, new, cond);
}
