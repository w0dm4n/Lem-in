/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 06:49:55 by frmarinh          #+#    #+#             */
/*   Updated: 2015/08/20 11:08:17 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		**s_bin_name(void)
{
	static char		*st_env = NULL;

	return (&st_env);
}

void			ft_set_bin_name(char *name)
{
	*s_bin_name() = name;
}

char			*ft_get_bin_name(void)
{
	return (*s_bin_name());
}

char			**ft_get_addr_bin_name(void)
{
	return (s_bin_name());
}
