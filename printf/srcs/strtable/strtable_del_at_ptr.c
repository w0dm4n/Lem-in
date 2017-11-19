/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtable_del_at_ptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:54:06 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/05 20:16:27 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_strtable_del_at_ptr(char ***atbl, void *ptr)
{
	ft_table_del_at_ptr((void ***)atbl, ptr, &free);
}
