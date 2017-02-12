# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/18 15:25:15 by mhaziza           #+#    #+#              #
#    Updated: 2017/02/12 16:38:52 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fractol
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I. -g
RM		=   rm -f
MLX		=	-I./mlx/mlx.h ./mlx/libmlx.a -framework OpenGL -framework Appkit
LIBFT	=	 -L./libft -lft
SRCS	=	fractol.c \
			mousehook_utils.c \
			keyhook_utils.c \
			draw_utils.c \
			julia.c \
			ihm_utils.c \
			threads_utils.c \

OBJS	=   $(SRCS:.c=.o)

LIBFT_PATH	= ./libft

all:	$(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAG) $(SRCS) $(MLX) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean

fclean:	clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re:		fclean all

.PHONY:		all clean fclean re
