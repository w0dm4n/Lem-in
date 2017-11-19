/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 14:18:09 by frmarinh          #+#    #+#             */
/*   Updated: 2015/02/22 14:18:41 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*cpydst;
	const char	*cpysrc;
	size_t		n;
	size_t		len;

	cpydst = dst;
	cpysrc = src;
	n = size;
	while (n-- != 0 && *cpydst != '\0')
		cpydst++;
	len = cpydst - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(cpysrc));
	while (*cpysrc != '\0')
	{
		if (n != 1)
		{
			*cpydst++ = *cpysrc;
			n--;
		}
		cpysrc++;
	}
	*cpydst = '\0';
	return (len + (cpysrc - src));
}
