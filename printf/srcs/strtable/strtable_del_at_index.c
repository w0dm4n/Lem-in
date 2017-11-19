/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtable_del_at_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:52:55 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/05 20:16:13 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_strtable_del_at_index(char ***atbl, size_t index)
{
	ft_table_del_at_index((void ***)atbl, index, &free);
}
