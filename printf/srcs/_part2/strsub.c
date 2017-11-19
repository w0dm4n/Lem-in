/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 05:52:36 by frmarinh          #+#    #+#             */
/*   Updated: 2016/03/23 05:52:36 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	size_t	j;

	str = NULL;
	if (s == NULL || len == 0)
		return (str);
	i = start;
	j = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str)
	{
		while (s[i] && j < len)
		{
			str[j] = s[i];
			i++;
			j++;
		}
		str[j] = '\0';
	}
	return (str);
}
