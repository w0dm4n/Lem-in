/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:35:28 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/23 10:35:31 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_comment		*new_comment(char *name)
{
	t_comment	*comment;

	if (!(comment = (t_comment*)malloc(sizeof(struct s_comment))))
		return (NULL);
	comment->name = ft_strdup(name);
	comment->next = NULL;
	return (comment);
}
