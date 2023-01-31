# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 16:37:58 by nicolas           #+#    #+#              #
#    Updated: 2023/01/31 00:39:13 by nicolas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=		fractol.a
EXEC				:=		./fractol

#------------------------------------------------#
#   PATHS                                        #
#------------------------------------------------#

SRC_DIR				:=		srcs
OBJ_DIR				:=		objs
INC_DIR				:=		includes
MLX_DIR				:=		mlx_linux

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

SRCS				:=		fract-ol \
							args_verification/verify_args \
							args_verification/error_messages \
							utils/set_write_color \
							utils/fractals \
							utils/ft_putchar_fd \
							utils/ft_putstr_fd \
							utils/ft_putendl_fd \
							utils/ft_putnbr_fd \
							utils/ft_atolli \
							utils/ft_tolower \
							utils/ft_lower_str \
							utils/ft_str_is_nbr \
							utils/ft_strcmp \
							utils/usage_indications \
							hooks/test_keycode \
							hooks/set_hooks \
							hooks/hook_numbers \
							hooks/hook_arrows \
							hooks/hook_iterations \
							hooks/hook_colorshift \
							hooks/hook_mouse \
							hooks/hook_zoom \
							draw/fill_display \
							draw/colors \
							draw/pixels \
							draw/draw_mandelbrot \
							draw/draw_julia \
							draw/draw_burning_ship \
							draw/draw_tricorn \

SRCS_C				:=		$(addsuffix .c, $(SRCS))
CC_SRCS_C			:=		$(addsuffix $(SRC_DIR)/, $(SRCS_C))

OBJS				:=		$(SRCS_C:%.c=$(OBJ_DIR)/%.o)

MLX_OBJ				:=		-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_LINK			:=		-I/usr/include -Imlx_linux #-O3

#------------------------------------------------#
#   COMMANDS                                     #
#------------------------------------------------#

CC					:=		gcc
AR					:=		ar -rcs
INCS				:=		-I $(INC_DIR)
CFLAGS				:=		-Wall -Wextra -Werror -g
RM					:=		rm -f

#------------------------------------------------#
#   COLORS			                             #
#------------------------------------------------#

COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_END=\033[0m

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all:				$(NAME)

$(NAME):			$(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(NAME) $(MLX_OBJ) -o $(EXEC)

$(OBJS):			$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCS) $(MLX_LINK) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean:				clean
	$(RM) $(NAME)
	$(RM) $(EXEC)

re:					fclean all

.PHONY: all clean fclean re

