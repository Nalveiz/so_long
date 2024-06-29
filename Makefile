NAME = so_long
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
MINILIBX = ./mlx/libmlx.a
SRCS = file_control.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		main.c \
		maps_control_1.c \
		map_control.c \
		move_key.c \
		error_utils.c \
		utils.c \

OBJS = $(SRCS:.c=.o)
all: ${NAME}

$(NAME): $(OBJS) $(SRCS)
	@make -C ./mlx &> /dev/null
	@$(CC) $(CFLAGS) $(SRCS) $(MINILIBX) $(LDFLAGS) -o $(NAME)
	@echo "\033[30m                    __                 "
	@echo "\033[30m   _________       / /___  ____  ____ _"
	@echo "\033[30m  / ___/ __ \     / / __ \/ __ \/ __ \`/"
	@echo "\033[97m (__  ) /_/ /    / / /_/ / / / / /_/ / "
	@echo "\033[97m/____/\____/____/_/\____/_/ /_/\__, /  "
	@echo "\033[97m          /_____/             /____/   "
	@echo "\033[0m"
	@echo "The game is ready to play!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) so_long.dSYM -s
	@echo "Object files cleaned!"


fclean:		clean
	@make -C ./mlx clean -s
	@rm -rf $(NAME) -s
	@echo "The game is removed!"

re:			fclean all

.PHONY:		all clean fclean re


