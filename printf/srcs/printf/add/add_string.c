/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 23:18:57 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/17 02:26:09 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/printf.h"

static void		s_strjoin(t_printf *t, char *s1, char *s2, unsigned int len)
{
	ft_memcpy(s1 + t->len, s2, len - t->len);
	t->len += (len - t->len);
	ft_strdel(&s2);
}

static void		s_new_buffer(t_printf *t, char *s)
{
	unsigned int	len;
	char			*tmp;

	tmp = NULL;
	if (s == NULL)
		return ;
	len = ft_strlen(s);
	if (t->buffer != NULL)
		len = t->len + len;
	t->buffer_size = len + BUFF_SIZE;
	if ((tmp = ft_strnew(t->buffer_size)) == NULL)
		return ((void)ft_strdel(&s));
	ft_memcpy(tmp, t->buffer, t->len);
	ft_memcpy(tmp + t->len, s, ft_strlen(s));
	ft_strdel(&t->buffer);
	t->buffer = tmp;
	t->len += ft_strlen(s);
	ft_strdel(&s);
}

void			add_string(t_printf *t, char *s)
{
	unsigned int	len;

	if (s == NULL || *s == '\0')
		return (ft_strdel(&s));
	len = ft_strlen(s);
	if (t->buffer != NULL)
		len = t->len + len;
	if (len > t->buffer_size)
		return (s_new_buffer(t, s));
	if (t->buffer != NULL)
		s_strjoin(t, t->buffer, s, len);
}
