/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_void.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 15:46:45 by frmarinh          #+#    #+#             */
/*   Updated: 2016/03/29 10:19:59 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/printf.h"

#include <stdarg.h>

void	*arg_get_void(t_printf *t)
{
	return ((void *)va_arg(t->args, void *));
}
