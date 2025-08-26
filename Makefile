# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 20:45:22 by ayusa             #+#    #+#              #
#    Updated: 2025/08/26 20:38:37 by ayusa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c so_long_util.c check_path.c so_long.c display_map.c operation.c \
		read_map.c valid_map.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

MLX_DIR = $(HOME)/.local/opt/minilibx-linux
INCS    = -I$(MLX_DIR)
LIBS    = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
GET_NEXT_LINE_DIR = get_next_line

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a

all: $(NAME)


$(NAME): $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(GET_NEXT_LINE) $(FT_PRINTF) $(LIBS) $(LIBFT)
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
