/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:23:05 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/12 13:23:06 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char		*ft_strndup(const char *src, size_t n)
{
	char	*res;
	char	*tmp;
	char	*s;

	s = (char*)src;
	if (!src || !(res = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	tmp = res;
	while (*s && n-- > 0)
		*res++ = *s++;
	*res = '\0';
	return (tmp);
}
