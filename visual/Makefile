# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/05 17:16:26 by rnovodra          #+#    #+#              #
#    Updated: 2018/09/05 17:16:27 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	+=	-s

NAME		=	../visu

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
INC_DIR		=	./inc/
LIB_DIR		=	./../lib/

SRC			=	main.c					\
				ftlmnv_error.c			\
				ftlmnv_exit.c			\
				ftlmnv_read_data.c		\
				ftlmnv_pars_ants.c		\
				ftlmnv_pars_rooms.c		\
				ftlmnv_room_format.c	\
				ftlmnv_pars_links.c		\
				ftlmnv_pars_moves.c		\
				ftlmnv_init_sdl.c		\
				ftlmnv_create_backgrd.c	\
				ftlmnv_draw_farm.c		\
				ftlmnv_where_ants.c		\
				ftlmnv_ants_moving.c	\
				ftlmnv_keys.c			\
				ftlmnv_ants_at_st_end.c	\
				ftlmnv_instr_spec.c		\
				ftlmnv_find_room.c		\


OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT_DIR	=	$(LIB_DIR)libft/
LIBFT		=	$(LIBFT_DIR)libft.a

PRINTF_DIR	=	$(LIB_DIR)ft_printf/
LIBPRINTF	=	$(PRINTF_DIR)libftprintf.a

HEAD_VISU	=	$(INC_DIR)visual.h

HEAD_FLAGS	=	-I $(INC_DIR) -I $(PRINTF_DIR)$(INC_DIR) -I $(LIBFT_DIR)$(INC_DIR)
LIBS_FLAGS	=	-L $(PRINTF_DIR) -lft -L $(LIBFT_DIR) -lftprintf

SDL_HEAD	=	-I ~/.brew/include/
SDL_LIB		=	-L ~/.brew/lib -lSDL2 -lSDL2_image -lSDL2_ttf

CC_FLAGS	=	-Wall -Werror -Wextra -std=c11 -O2

CC			=	clang

BG			=	"\033[32;1m"
BR			=	"\033[31;1m"
EOC			=	"\033[0m"

all: $(LIBPRINTF) $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBPRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LIBS_FLAGS) $(SDL_LIB)
	echo ${BG}"visual is ready"${EOC}

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEAD_VISU)
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS) $(SDL_HEAD)
	echo ${BG}"[✓] $<"

clean:
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ)
	echo ${BR}"[✗] clean"

fclean: clean
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)
	echo ${BR}"[✗] $(NAME)"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all fclean clean re $(LIBPRINTF) $(LIBFT)

