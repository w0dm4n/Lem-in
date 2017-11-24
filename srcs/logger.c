/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:54:16 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/23 16:54:20 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void			log_ant(t_ant *ant, t_lemin *lemin)
{
	char	*path;
	t_room	*rooms;
	char	*file;
	int		fd;

	rooms = ant->following_path->rooms;
	fd = 0;
	if (!(path = ft_strnew(0)))
		return ;
	if (!(file = ft_strnew(0)))
		return ;
	while (rooms)
	{
		ft_asprintf(&path, "%s%s - ", path, rooms->name);
		rooms = rooms->next;
	}
	ft_asprintf(&path, "%s%s\n", path, get_end_room(lemin)->name);
	ft_asprintf(&file, "logs/ant_%d", ant->id);
	if ((fd = open(file, O_RDWR | O_CREAT, 0666)) != OPEN_ERROR)
		write(fd, path, ft_strlen(path));
	ft_strdel(&path);
	ft_strdel(&file);
}
