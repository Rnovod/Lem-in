# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/28 17:17:15 by rnovodra          #+#    #+#              #
#    Updated: 2018/04/28 17:17:19 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRC			=	ft_printf.c \
				ft_dprintf.c \
				ft_vdprintf.c \
				ft_fprintf.c \
				ft_print_buff.c \
				ft_spec.c \
				ft_set_flags.c \
				ft_conv.c \
				ft_star.c \
				ft_count_arg.c \
				ft_int.c \
				ft_printf_itoa.c \
				ft_count_dig.c \
				ft_width_prec_sign.c \
				ft_char.c \
				ft_string.c \
				ft_wstring.c \
				ft_write_nbr_chr.c \
				ft_float.c \
				ft_printf_dtoa.c \
				ft_handle_nan.c \
				ft_get_float_val.c \
				ft_expo_form.c \
				ft_g_float.c \
				ft_color.c \
				ft_nonprint_char_str.c \
				ft_print_date.c \
				ft_two_dimensional_array.c \
				ft_a_float.c 
				
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
INC_DIR		=	./inc/

INC_LIBDIR	=	./../libft/$(INC_DIR)	

LIBFT_HEAD	=	$(INC_LIBDIR)libft.h

HEADER		=	$(INC_DIR)ft_printf.h

HEAD_FLAGS	=	-I $(INC_DIR) -I $(INC_LIBDIR)

CC_FLAGS	=	-Wall -Werror -Wextra -std=c11

CC			=	gcc

BG			=	"\033[32;1m"
BR			=	"\033[31;1m"
EOC			=	"\033[0m"

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ${BG}"ft_printf is ready"${EOC}
	
$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEADER)
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS)
	@echo ${BG}"[✓] $<"

clean:
	@rm -rf $(OBJ)
	@echo ${BR}"[✗] clean"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo ${BR}"[✗] $(NAME)"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all fclean clean re 
