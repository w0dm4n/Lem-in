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
# include <fcntl.h>
# include "../libft/includes/libft.h"

# define START_ROOM			"##start"
# define END_ROOM			"##end"
# define ROOM_DELIM			' '
# define PIPE_DELIM			'-'
# define COMMENT_DELIM		'#'
# define BOOL				int
# define TRUE				1
# define FALSE				0
# define MAX_ANTS			100000
# define MAX_PATHS			100
# define _
# define OPEN_ERROR			-1

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

typedef struct				s_path
{
	t_room					*rooms;
	BOOL					valid;
	struct s_path			*next;
}							t_path;

typedef struct				s_ant
{
	int						id;
	t_room					*current_room;
	t_path					*following_path;
	BOOL					in_end_room;
	struct s_ant			*next;
}							t_ant;

typedef struct				s_command
{
	char					*name;
	struct s_command		*next;
}							t_command;

typedef struct				s_comment
{
	char					*name;
	struct s_comment		*next;
}							t_comment;

typedef struct				s_lemin
{
	int						ants_length;
	BOOL					waiting_for_start_room;
	BOOL					waiting_for_end_room;
	t_room					*rooms;
	t_ant					*ants;
	t_path					*paths;
	t_command				*commands;
	t_comment				*comments;
	char					*map_raw;
}							t_lemin;

typedef struct				s_forbidden
{
	char					*room_name;
	struct s_forbidden		*next;
}							t_forbidden;

/*
**	COMMAND
*/
t_command					*new_command(char *name);

/*
**	COMMENT
*/
t_comment					*new_comment(char *name);

/*
**	ROOMS LISTS
*/
void						append_room_list(t_room *room, t_lemin *lemin);
t_room						*get_room_by_name(char *name, t_lemin *lemin);
t_room						*get_start_room(t_lemin *lemin);
t_room						*get_end_room(t_lemin *lemin);
void						print_rooms(t_room *rooms);

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
**	PATHS LISTS
*/
void						append_paths_list(t_path *path, t_path *paths);
int							count_paths(t_path *paths);
t_path						*remove_from_paths_list(t_path *p, t_path *ps);
int							count_rooms(t_room *rooms);
void						append_path_room_list(t_room *room, t_path *path);

/*
**	COMMANDS LISTS
*/
void						append_commands_list(t_command *command,
		t_lemin *lemin);

/*
**	COMMENTS LISTS
*/
void						append_comments_list(t_comment *comment,
		t_lemin *lemin);
int							count_comments(t_comment *comments);

/*
**	LEMIN
*/
t_lemin						*alloc_lemin(void);

/*
**	ANT
*/
void						get_ants_length(t_lemin *lemin, char *line);
void						init_ants(t_lemin *lemin);
void						set_ant_room(t_ant *ant, t_room *room);
void						move_ant(t_ant *ant, t_room *to, t_lemin *lemin);

/*
**	PARSER
*/
void						parse_room(t_lemin *lemin, char *line);
void						parse_pipe(t_lemin *lemin, char *line);

/*
**	ROOM
*/
t_room						*new_room(char *name, int x, int y, t_lemin *lemin);
t_room						*copy_room(t_room *cpy);

/*
**	PATH
*/
t_path						*alloc_path(t_room *room);
void						switch_rooms(t_path *larger, t_path *smaller);

/*
**	PIPE
*/
void						link_rooms(t_room *first, t_room *second, \
	t_lemin *lemin);
int							count_pipes(t_room *room);

/*
**	FREE LEMIN
*/
void						free_lemin(t_lemin *lemin);
void						free_path(t_path *base);

/*
**	TIMELINE
*/
void						move_ant(t_ant *ant, t_room *room, t_lemin *lemin);

/*
**	PATH FINDING
*/
BOOL						find_paths(t_room *room, t_path *path,
		t_lemin *lemin, t_room *end_room);

/*
**	PATH CHECKER
*/
void						check_paths_validity(t_path *paths, t_lemin *lemin);

/*
**	PATH CHOOSER
*/
void						select_path(t_ant *ant, t_lemin *lemin);
void						range_paths(t_lemin *lemin);

/*
**	TIMELINE
*/
void						start_timeline(t_lemin *lemin);
BOOL						ant_in_room(char *room_name, t_lemin *lemin);

/*
**	PRINT
*/
void						print_commands_and_comments(t_lemin *lemin);

/*
**	LOGGER
*/
void						log_ant(t_ant *ant, t_lemin *lemin);
#endif
