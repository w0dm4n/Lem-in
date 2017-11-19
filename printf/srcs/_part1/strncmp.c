/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 14:21:58 by frmarinh          #+#    #+#             */
/*   Updated: 2015/01/24 18:28:12 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while ((s1[i] == s2[i]) && (s1[i] != '\0') && (i < n - 1))
			i++;
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
