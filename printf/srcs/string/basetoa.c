/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basetoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 19:18:19 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/18 04:30:47 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

static void		s_addchar(char **s, char c)
{
	int		len;
	char	*tmp;

	len = 2;
	if (*s)
		len = ft_strlen(*s) + 1;
	if ((tmp = ft_strnew(len)) == NULL)
		return ;
	if (*s)
	{
		ft_strcpy(tmp, *s);
		tmp[len - 1] = c;
	}
	else
		tmp[0] = c;
	ft_strdel(s);
	*s = tmp;
}

static void		s_strcal(char **s, long long int n, char *base, size_t len)
{
	if (n < 0)
	{
		s_addchar(s, '-');
		n = n * -1;
	}
	if (n < (long long int)len)
		s_addchar(s, base[n]);
	else
	{
		s_strcal(s, n / len, base, len);
		s_addchar(s, base[n % len]);
	}
}

char			*ft_basetoa(long long int n, char *base)
{
	char	*str;
	size_t	len_base;

	str = NULL;
	len_base = ft_strlen(base);
	if (len_base < 2)
		return (NULL);
	s_strcal(&str, n, base, len_base);
	return (str);
}
