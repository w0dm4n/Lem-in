/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:24:18 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/12 13:24:20 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*save;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((ret = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	ret = f(lst);
	save = ret;
	if (ret == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		if ((tmp = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		tmp = f(lst);
		if (tmp == NULL)
			return (NULL);
		lst = lst->next;
		ret->next = tmp;
		ret = ret->next;
	}
	return (save);
}
