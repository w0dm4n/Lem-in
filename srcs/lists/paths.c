/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 04:01:08 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/22 04:01:14 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

#define VARS p = paths; prev = NULL; next = NULL

t_path		*remove_from_paths_list(t_path *path, t_path *paths)
{
	t_path		*p;
	t_path		*prev;
	t_path		*next;

	VARS;
	while (p)
	{
		if (p == path)
		{
			if (prev)
			{
				prev->next = p->next;
				free(p);
			}
			else
			{
				next = p->next;
				free(p);
				return (next);
			}
		}
		prev = p;
		p = p->next;
	}
	return (paths);
}

void		append_paths_list(t_path *path, t_path *paths)
{
	t_path	*tmp;

	tmp = paths;
	if (paths)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = path;
	}
	else
		paths = path;
}

int			count_paths(t_path *paths)
{
	t_path		*tmp;
	int			count;

	tmp = paths;
	count = 0;
	while (tmp)
	{
		count += 1;
		tmp = tmp->next;
	}
	return (count);
}
