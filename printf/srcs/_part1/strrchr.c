/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 14:25:28 by frmarinh          #+#    #+#             */
/*   Updated: 2015/02/22 15:11:16 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*chr;

	chr = NULL;
	if (*s == (char)c)
		chr = (char *)s;
	while (*s)
	{
		if (*s == c)
			chr = (char *)s;
		s++;
	}
	if (c == '\0')
		chr = (char *)s;
	return (chr);
}
