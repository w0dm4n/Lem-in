/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putiendl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:22:57 by frmarinh          #+#    #+#             */
/*   Updated: 2015/05/20 13:29:25 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <string.h>

void		ft_putiendl(char *s, ...)
{
	va_list		args;
	char		*str;
	char		*tmp;
	int			len;

	len = 0;
	len += ft_strlen(s);
	va_start(args, s);
	while ((str = (char *)va_arg(args, char *)))
		len += ft_strlen(str);
	va_end(args);
	str = ft_strnew(len + 1);
	str = ft_strcat(str, s);
	va_start(args, s);
	while ((tmp = (char *)va_arg(args, char *)))
		str = ft_strcat(str, tmp);
	va_end(args);
	str[len] = '\n';
	ft_putstr(str);
	ft_strdel(&str);
}
