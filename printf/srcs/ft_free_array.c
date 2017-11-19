/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 19:06:46 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/16 23:05:33 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_array(void **array)
{
	char	**cast;
	int		i;

	i = 0;
	cast = (char**)array;
	if (array != NULL)
	{
		while (cast[i])
			ft_strdel(&cast[i++]);
		free(array);
		array = NULL;
	}
}
