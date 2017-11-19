/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   straddchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 14:32:52 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/19 18:20:23 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_straddchar(char **s, const char c)
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
	{
		tmp[0] = c;
	}
	ft_strdel(s);
	*s = tmp;
}
