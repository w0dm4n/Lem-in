/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 15:43:41 by frmarinh          #+#    #+#             */
/*   Updated: 2016/03/29 10:19:15 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/printf.h"

#include <stdarg.h>

int				arg_get_int(t_printf *t)
{
	return ((int)va_arg(t->args, int));
}

unsigned int	arg_get_uint(t_printf *t)
{
	return ((unsigned int)va_arg(t->args, unsigned int));
}
