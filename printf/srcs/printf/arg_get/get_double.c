/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 08:28:43 by frmarinh          #+#    #+#             */
/*   Updated: 2016/03/29 10:19:05 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/printf.h"

#include <stdarg.h>

double			arg_get_double(t_printf *t)
{
	return ((double)va_arg(t->args, double));
}

long double		arg_get_longdouble(t_printf *t)
{
	return ((long double)va_arg(t->args, long double));
}
