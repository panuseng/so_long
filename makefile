# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plaophit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 22:14:46 by seng              #+#    #+#              #
#    Updated: 2024/04/01 12:52:48 by plaophit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

FILES = main.c get.c map.c check.c move.c GNL/get_next_line.c GNL/get_next_line_utils.c ft_printf/ft_printf.c ft_printf/print_2.c\
		libft/ft_strdup.c libft/ft_strlcpy.c

MLX_FLAG = MLX42/build/libmlx42.a -Iinclude -lglfw

all: $(NAME)

$(NAME): $(FILES)
	cc $(CFLAGS)  $(FILES) -o $@ $(MLX_FLAG)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
