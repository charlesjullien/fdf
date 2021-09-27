# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 14:18:55 by cjullien          #+#    #+#              #
#    Updated: 2021/09/27 13:31:53 by cjullien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
CC		=	clang
FLAGS	=	-O3 -Wall -Wextra -Werror
SRCS	=	srcs/main.c srcs/fdf_utils.c srcs/find_vars.c srcs/find_vars2.c srcs/draw.c srcs/bresenham.c
INCS	=	$(addprefix includes/, fdf.h)
OBJS	=	$(SRCS:.c=.o)


all: $(NAME)


$(NAME): $(OBJS) $(INCS)
	make -C libft
	make -C libmlx
	$(CC) $(FLAGS) -I includes -o $(NAME) $(OBJS) -Llibft -lft -Lmlx -Llibmlx -lmlx -lX11 -lbsd -lm -lXext

%.o: %.c $(INCS)
	$(CC) $(FLAGS) -I includes -Imlx -c $< -o $@

clean:
	@make fclean -C libft
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

