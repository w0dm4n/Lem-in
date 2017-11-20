/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:45:17 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/19 22:45:26 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include <stdlib.h>
# include "printf/printf.h"
# include "../libft/includes/libft.h"

# define START_ROOM			"##start"
# define END_ROOM			"##end"
# define ROOM_DELIM			' '
# define PIPE_DELIM			'-'
# define BOOL				int
# define TRUE				1
# define FALSE				0
# define MAX_ANTS			100000

typedef struct				s_pipe
{
	void					*room;
	struct s_pipe			*next;
}							t_pipe;

typedef struct				s_room
{
	char					*name;
	int						x;
	int						y;
	BOOL					start_room;
	BOOL					end_room;
	struct s_room			*next;
	struct s_pipe			*pipes;
}							t_room;

typedef struct				s_ant
{
	int						id;
	t_room					*current_room;
	struct s_ant			*next;
}							t_ant;

typedef struct				s_lemin
{
	int						ants_length;
	BOOL					waiting_for_start_room;
	BOOL					waiting_for_end_room;
	t_room					*rooms;
	t_ant					*ants;
}							t_lemin;

/*
**	ROOMS LISTS
*/
void						append_room_list(t_room *room, t_lemin *lemin);
t_room						*get_room_by_name(char *name, t_lemin *lemin);
t_room						*get_start_room(t_lemin *lemin);
t_room						*get_end_room(t_lemin *lemin);

/*
**	PIPES LISTS
*/
void						append_room_pipe(t_pipe *pipe, t_room *room);
BOOL						room_linked(t_room *first, t_room *second);

/*
**	ANTS LISTS
*/
void						append_ants_list(t_ant *new_ant, t_lemin *lemin);

/*
**	LEMIN
*/
t_lemin						*alloc_lemin(void);

/*
**	ANT
*/
void						get_ants_length(t_lemin *lemin, char *line);
void						init_ants(t_lemin *lemin);

/*
**	PARSER
*/
void						parse_room(t_lemin *lemin, char *line);
void						parse_pipe(t_lemin *lemin, char *line);

/*
**	ROOM
*/
t_room						*new_room(char *name, int x, int y, t_lemin *lemin);

/*
**	PIPE
*/
void						link_rooms(t_room *first, t_room *second, \
	t_lemin *lemin);

/*
**	FREE LEMIN
*/
void						free_lemin(t_lemin *lemin);
#endif
