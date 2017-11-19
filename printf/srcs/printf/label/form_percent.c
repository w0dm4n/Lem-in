/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:30:22 by frmarinh          #+#    #+#             */
/*   Updated: 2016/03/29 10:32:14 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/conversion/to_string.h"

void	form_percent(t_printf *t)
{
	t->flags.prec = -1;
	to_string(t, ft_strdup("%"));
}
