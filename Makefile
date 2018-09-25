# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/28 17:17:15 by rnovodra          #+#    #+#              #
#    Updated: 2018/09/23 10:27:53 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	+=	-s

NAME		=	lem-in

SRC			=	main.c				\
				ftlmn_output.c		\
				ftlmn_read_farm.c	\
				ftlmn_mng_argv.c	\
				ftlmn_ants.c		\
				ftlmn_rooms.c		\
				ftlmn_room_format.c \
				ftlmn_command_room.c\
				ftlmn_links.c		\
				ftlmn_command.c		\
				ftlmn_comment.c		\
				ftlmn_bfs.c			\
				ftlmn_find_ways.c	\
				ftlmn_go_back.c		\
				ftlmn_print_all.c	\
				ftlmn_put_ants.c	\
				ftlmn_exit.c		\
				ftlmn_error.c		\

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
INC_DIR		=	./inc/
LIB_DIR		=	./lib/
VISU_DIR	=	./visual/

LIBFT_DIR	=	$(LIB_DIR)libft/

LIBFT		=	$(LIBFT_DIR)libft.a

PRINTF_DIR	=	$(LIB_DIR)ft_printf/

LIBPRINTF	=	$(PRINTF_DIR)libftprintf.a

HEAD_LEMIN	=	$(INC_DIR)lem_in.h

HEAD_FLAGS	=	-I $(INC_DIR) -I $(PRINTF_DIR)$(INC_DIR) -I $(LIBFT_DIR)$(INC_DIR)

LIBS_FLAGS	=	-L $(PRINTF_DIR) -lft -L $(LIBFT_DIR) -lftprintf

CC_FLAGS	=	-Wall -Werror -Wextra -std=c11 -O2

CC			=	clang

BG			=	"\033[32;1m"
BR			=	"\033[31;1m"
EOC			=	"\033[0m"

all: $(LIBPRINTF) $(LIBFT) $(NAME) visu

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBPRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LIBS_FLAGS)
	echo ${BG}"lem-in ready"${EOC}

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEAD_LEMIN)
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS) 
	echo ${BG}"[✓] $<"

visu:
	make -C $(VISU_DIR)

clean:
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(VISU_DIR)
	rm -rf $(OBJ)
	echo ${BR}"[✗] clean"

fclean: clean
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(VISU_DIR)
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)
	echo ${BR}"[✗] $(NAME)"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all fclean clean re $(LIBPRINTF) $(LIBFT) visu
