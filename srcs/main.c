/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:24:05 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/19 22:24:37 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static BOOL		check_state(t_lemin *lemin, char *line)
{
	BOOL	res;

	res = FALSE;
	if (!ft_strcmp(line, START_ROOM))
	{
		lemin->waiting_for_start_room = TRUE;
		res = TRUE;
	}
	else if (!ft_strcmp(line, END_ROOM))
	{
		lemin->waiting_for_end_room = TRUE;
		res = TRUE;
	}
	return (res);
}

static void		parse_commands_and_comments(t_lemin *lemin, char *line)
{
	if (line[0] == COMMENT_DELIM && ft_strlen(line) > 2)
	{
		(line[1] == COMMENT_DELIM) ?
		append_commands_list(new_command(line), lemin)
		: append_comments_list(new_comment(line), lemin);
	}
}

#define VAR char *line = NULL

static void		parse_entry(t_lemin *lemin)
{
	VAR;
	while ((get_next_line(STDIN_FILENO, &line)) > 0)
	{
		if (line != NULL && ft_strlen(line) > 0)
		{
			parse_commands_and_comments(lemin, line);
			if (lemin->ants_length > 0)
			{
				if (!check_state(lemin, line))
				{
					if (line[0] != COMMENT_DELIM)
					{
						if (ft_strchr(line, ROOM_DELIM) != NULL)
							parse_room(lemin, line);
						else if (ft_strchr(line, PIPE_DELIM) != NULL)
							parse_pipe(lemin, line);
					}
				}
			}
			else
				get_ants_length(lemin, line);
			ft_asprintf(&lemin->map_raw, "%s\n%s", lemin->map_raw, line);
			free(line);
		}
	}
}

static void		print_list(t_room *rooms)
{
	t_room *p;

	p = rooms;
	while (p)
	{
		ft_printf("%s - ", p->name);
		p = p->next;
	}
	ft_printf("\n");
}

int				main(int argc, char **argv)
{
	t_lemin		*lemin;

	if (!(lemin = alloc_lemin()))
		return (-1);
	parse_entry(lemin);
	if (lemin->ants_length > 0 && get_start_room(lemin) != NULL
		&& get_end_room(lemin) != NULL)
	{
		print_commands_and_comments(lemin);
		init_ants(lemin);
		find_paths(get_start_room(lemin), lemin->paths, lemin,
			get_end_room(lemin));
		check_paths_validity(lemin->paths, lemin);
		if (count_paths(lemin->paths) > 0)
			start_timeline(lemin);
		else
			ft_printf("No path found for this map.. please check the datas\n");
	}
	else
		ft_printf("Invalid map.. please check the datas\n");
	free_lemin(lemin);
	return (0);
}
