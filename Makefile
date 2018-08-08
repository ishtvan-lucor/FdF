#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 15:27:53 by azaporoz          #+#    #+#              #
#    Updated: 2018/07/31 15:50:08 by ikoloshy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
FLG = -Wall -Wextra -Werror
FRM = -framework AppKit -framework OpenGL
SRC = src/main.c \
	  src/handle_error.c \
	  src/validation.c \
	  src/make_visual_environment.c \
	  src/draw_line.c \
	  src/default_map.c \
	  src/catch_hooks.c \
	  src/move_map.c \
	  src/draw_img.c \
	  src/zoom.c \
	  src/rotation.c \
	  src/new_window.c \
	  src/start.c \
	  src/draw_legend.c \
	  src/free_handle.c \

HDR = includes/fdf.h
OFL = $(SRC:.c=.o)
LIB = libft/libft.a
MLX = -lmlx -I minilibx_macos -L minilibx_macos

.NOTPARALLEL: all clean fclean re

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OFL) 
	@gcc $(FLG) -o $@ $(OFL) -I $(HDR) -L libft/ -lft $(MLX) $(FRM)
	@echo "\033[1;32mFdF is ready to work\033[0m"

%.o: %.c $(HDR) $(LIB)
	@gcc -c $< -o $@ $(FLG) 
$(LIB):
	@make -C ./libft

clean:
	@/bin/rm -f $(OFL)
	@make fclean -C ./libft
	@echo "\033[1;32mObjects files FDF were deleted\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[1;32mFDF was deleted\033[0m"

re: fclean all
