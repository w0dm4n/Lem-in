/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtable_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:46:10 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/01 19:47:16 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtable_push_back(char ***atbl, void *new)
{
	ft_table_push_back((void ***)atbl, new);
}
