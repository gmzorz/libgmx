# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: goosterl <goosterl@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/22 15:28:18 by goosterl      #+#    #+#                  #
#    Updated: 2021/12/15 10:21:56 by goosterl      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	./lib/gmlib.a
CC		=	gcc
LIBCC	=	ar rcs
CFLAGS	=	-Wall -Werror -Wextra -O2 -g -ffast-math
FRAMEW	=	-framework OpenGL -framework AppKit
LIBINC	=	./src/libft/libft.a			\
			./src/minilibx/libmlx.a

INC		=	./inc/

SRC		=	./src/gmx_init.c			\
			./src/global.c				\
			./src/shader_add.c			\
			./src/frameloop.c			\
			./src/geometry.c			\
			\
			./src/vec_init.c			\
			./src/vec_clamp.c			\
			./src/vec_cross.c			\
			./src/vec_dot.c				\
			./src/vec_length.c			\
			./src/vec_min_max.c			\
			./src/vec_normalize.c		\
			./src/vec_saturate.c		\
			./src/vec_quaternion.c		\
			./src/vec_arrange.c			\
			./src/vec_trig.c			\
			./src/vec_trigarc.c			\
			./src/vec_mod.c				\
			./src/math_min_max.c		\
			./src/math_clamp.c			\
			./src/math_smoothstep.c		\
			./src/math_smoothmin.c		\
			./src/math_lerp.c			\
			./src/mat.c					\
			./src/mat_transpose.c		\
			./src/mat_rotate.c			\
			./src/mat_mul.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	prepare $(OBJ)
			@cp ./src/libft/libft.a ./lib/libft.a
			@cp ./src/minilibx/libmlx.a ./lib/libmlx.a
			$(LIBCC) $(NAME) $(OBJ) $(LIBINC)

prepare:
			@make -s -C ./src/libft/
			@make -s -C ./src/minilibx/
			cp ./src/libft/libft.h ./inc/libft.h
			cp ./src/minilibx/mlx.h ./inc/mlx.h

%.o:		%.c
			$(CC) -I $(INC) $(CFLAGS) -c -o $@ $<

clean:
			rm -rf $(OBJ)
			rm -rf $(NAME)

# make clean -C ./libft/

fclean:		clean
			make fclean -C ./src/libft/
			make clean -C ./src/minilibx/
			rm -rf $(NAME)

re:			fclean all

be:			clean all

.PHONY:		all, clean, fclean, re
