# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/20 17:57:50 by frmarinh          #+#    #+#              #
#    Updated: 2017/11/17 01:59:46 by frmarinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LEM_IN	=	Lem-in
EXE_NAME	=	lem-in

NAME		=   Lem-in
NAMEBASE    =   $(shell basename $(NAME))
LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`
MAX_COLS	=	$$(echo "$$(tput cols)-24-$(LENGTHNAME)"|bc)

CC			= gcc
FLAGS		=
FLAGS_O		=
#FLAGS		= -Wall -Wextra -Werror
#FLAGS_O		= -Wall -Wextra -Werror

SRCDIR_LEM_IN		=	srcs/
OBJDIR_LEM_IN		=	objs/

INCDIR				=	includes/
LIBFT_DIR			=	libft/
LIBFT_LIB			=	$(LIBFT_DIR)libft.a

PRINTF_DIR			=	printf/
PRINTF_LIB			=	$(PRINTF_DIR)libprintf.a

SRCBASE_LEM_IN	=	\
					main.c						\
					lemin.c						\
					ant.c						\
					parser.c					\
					room.c						\
					pipe.c						\
					lists/rooms.c				\
					lists/pipes.c				\
					lists/ants.c				\
					lists/paths.c				\
					free.c						\
					pathfinding.c				\
					timeline.c					\
					path.c						\
					paths_validity.c			\

SRCS_LEM_IN			=	$(addprefix $(SRCDIR_LEM_IN), $(SRCBASE_LEM_IN))
OBJS_LEM_IN			=	$(addprefix $(OBJDIR_LEM_IN), $(SRCBASE_LEM_IN:.c=.o))

.SILENT:

all:		$(NAME)

$(NAME):
	if test -f $(EXE_NAME) ; then												\
		echo "make: Nothing to be done for \`all\`.";				        		\
	else																			\
		make re -C libft/ &&														\
		make LEM_IN && 																\
		echo "\r\033[38;5;184m👥  AUTHOR(s): \033[0m\033[K" && 						\
		echo "\r\033[38;5;15m`cat auteur | sed s/^/\ \ \ \ -/g`\033[0m\033[K" &&	\
		echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K";				\
	fi

$(OBJDIR_LEM_IN):
	mkdir -p $(OBJDIR_LEM_IN)
	mkdir -p $(dir $(OBJS_LEM_IN))

$(OBJDIR_LEM_IN)%.o : $(SRCDIR_LEM_IN)%.c | $(OBJDIR_LEM_IN)
	$(CC) $(FLAGS) -MMD -c $< -o $@											\
		-I $(LIBFT_DIR)$(INCDIR)											\
		-I $(PRINTF_DIR)$(INCDIR)											\
		-I $(INCDIR)														\

fcleanlib:	fclean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re:			fclean all

relib:		fclean fcleanlib all

.PHONY:		fclean fcleanlib clean re relib

LEM_IN: $(OBJDIR_LEM_IN) $(OBJS_LEM_IN)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(FLAGS) $(FLAGS_O) -o $(EXE_NAME) $(OBJS_LEM_IN) $(LIBFT_LIB) $(PRINTF_LIB)
	echo "\r\033[38;5;22m📗  MAKE $(NAME_LEM_IN)"

clean:
	@rm -rf $(OBJDIR_LEM_IN)
	@make -C $(LIBFT_DIR) clean
	#@make -C $(PRINTF_DIR) clean
	echo "\r\033[38;5;124m📕  CLEAN $(OBJDIR_LEM_IN)\033[0m\033[K";

fclean:		clean
	@rm -rf $(EXE_NAME)
	@make -C $(LIBFT_DIR) fclean
	#@make -C $(PRINTF_DIR) fclean
	echo "\r\033[38;5;124m📕  FCLEAN $(NAME_LEM_IN)\033[0m\033[K";

-include $(OBJS:.o=.d)
