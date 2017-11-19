/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtable_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:38:59 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/01 19:41:22 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_strtable_clear(char ***atbl)
{
	ft_table_clear((void ***)atbl, &free);
}
