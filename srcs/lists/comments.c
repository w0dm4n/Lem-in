/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:35:35 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/23 10:35:40 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int				count_comments(t_comment *comments)
{
	t_comment	*c;
	int			count;

	count = 0;
	c = comments;
	while (c)
	{
		count += 1;
		c = c->next;
	}
	return (count);
}

void			append_comments_list(t_comment *comment, t_lemin *lemin)
{
	t_comment	*c;

	if (!comment)
		return ;
	c = lemin->comments;
	if (lemin->comments)
	{
		while (c->next)
			c = c->next;
		c->next = comment;
	}
	else
		lemin->comments = comment;
}
