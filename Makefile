# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 20:45:22 by ayusa             #+#    #+#              #
#    Updated: 2025/07/29 20:28:56 by ayusa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c av_to_map.c util.c check_path.c so_long.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

%.o: %.
	$(CC) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
GET_NEXT_LINE_DIR = get_next_line
MLX_DIR = ./minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm


all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(GET_NEXT_LINE) $(LIBFT) $(FT_PRINTF) $(LIBS)
	@echo "\[\033[4;35m                                                            \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███   ███  ▄███            \n\
	███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      \n\
	        ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     \n\
	▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀      \n\
                                                                       	 		\033[0m"
	@echo "                                \033[44mBy: ayusa"

$(GET_NEXT_LINE): $(LIBFT)
	make -C $(GET_NEXT_LINE_DIR)

$(FT_PRINTF): $(LIBFT)
	make -C $(FT_PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	make -C $(GET_NEXT_LINE_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean
	make -C $(GET_NEXT_LINE_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
