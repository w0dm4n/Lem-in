/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stridel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 21:41:46 by frmarinh          #+#    #+#             */
/*   Updated: 2015/04/26 15:41:43 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

void	ft_stridel(char **s, ...)
{
	va_list		args;
	char		**str;

	va_start(args, s);
	ft_strdel(s);
	while ((str = (char **)va_arg(args, char **)))
		ft_strdel(str);
	va_end(args);
}
