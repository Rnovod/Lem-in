# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 17:00:59 by rnovodra          #+#    #+#              #
#    Updated: 2017/11/17 19:43:42 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libft.a

SRC		=		ft_lstiter.c		\
				ft_putnbr_fd.c		\
				ft_strmapi.c		\
				ft_lstmap.c			\
				ft_putstr.c			\
				ft_strncat.c		\
				ft_lstnew.c			\
				ft_putstr_fd.c		\
				ft_strncmp.c		\
				ft_atoi.c			\
				ft_memalloc.c		\
				ft_strcat.c			\
				ft_strncpy.c		\
				ft_bubsort.c		\
				ft_memccpy.c		\
				ft_strchr.c			\
				ft_strnequ.c		\
				ft_bzero.c			\
				ft_memchr.c			\
				ft_strclen.c		\
				ft_strnew.c			\
				ft_clist.c			\
				ft_memcmp.c			\
				ft_strclr.c			\
				ft_strnstr.c		\
				ft_count_digits.c	\
				ft_memcpy.c			\
				ft_strcmp.c			\
				ft_strrchr.c		\
				ft_count_words.c	\
				ft_memdel.c			\
				ft_strcpy.c			\
				ft_strsplit.c		\
				ft_isalnum.c		\
				ft_memmove.c		\
				ft_strdel.c			\
				ft_strstr.c			\
				ft_isalpha.c		\
				ft_memset.c			\
				ft_strdup.c			\
				ft_strsub.c			\
				ft_isascii.c		\
				ft_pow.c			\
				ft_powf.c			\
				ft_powd.c			\
				ft_powld.c			\
				ft_sqrtf.c			\
				ft_strequ.c			\
				ft_strtrim.c		\
				ft_isdigit.c		\
				ft_prime.c			\
				ft_striter.c		\
				ft_swap.c			\
				ft_isprint.c		\
				ft_putchar.c		\
				ft_striteri.c		\
				ft_tolower.c		\
				ft_itoa.c			\
				ft_putchar_fd.c		\
				ft_strjoin.c		\
				ft_toupper.c		\
				ft_lstadd.c			\
				ft_putendl.c		\
				ft_strlcat.c		\
				ft_lstdel.c			\
				ft_putendl_fd.c		\
				ft_strlen.c			\
				ft_lstdelone.c		\
				ft_putnbr.c			\
				ft_strmap.c			\
				ft_arrnfree.c		\
				ft_arrfree.c		\
				ft_putarr.c			\
				ft_arrcpy.c			\
				ft_arrnew.c			\
				ft_arrlen.c			\
				ft_arrdup.c			\
				ft_arrcat.c			\
				ft_arrjoin.c		\
				ft_arr_realloc.c	\
				get_next_line.c		\
				ft_getnbr.c			\
				ft_atoi_base.c		\
				ft_itoa_base.c		\
				ft_print_memory.c	\
				ft_print_bits.c		\
				ft_gradient.c		\
				ft_randd.c			\
				ft_reverse_bits.c	\
				ft_qsort.c			\
				ft_read_file.c		\
				ft_isproc.c			\

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
INC_DIR		=	./inc/

HEAD_FLAGS	=	-I $(INC_DIR)

HEADER		=	$(INC_DIR)libft.h

CC_FLAGS	=	-Wall -Werror -Wextra -std=c11

CC			=	gcc

BG			=	"\033[32;1m"
BR			=	"\033[31;1m"
EOC			=	"\033[0m"

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ${BG}"libft.a is ready" ${EOC}

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEADER)
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS)
	@echo ${BG}"[✓] $<" ${EOC}

clean :
	@rm -rf $(OBJ)
	@echo ${BR}"[✗] cleaning" ${EOC}

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo ${BR}"[✗] $(NAME)" ${EOC}

re : fclean all

vpath %.c $(SRC_DIR)

.PHONY: all fclean clean re 
