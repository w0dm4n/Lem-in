/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:41:31 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/20 11:27:50 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errno/strerror.h"
#include "libft.h"

#include <errno.h>

char	*ft_strerror(void)
{
	static char		**t = NULL;

	if (t == NULL)
		ini_strerror(&t);
	if (t && errno > 0 && errno <= 106)
		return (t[errno]);
	return (NULL);
}
