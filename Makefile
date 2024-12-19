NAME = so_long

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRCS = main.c\
validation.c\
utils.c\
ft_split.c \
get_next_line/get_next_line_utils.c\
get_next_line/get_next_line.c\
init_st.c\
rectangle.c\
surrounded_by_walls.c\
check_elements.c\
is_map_playable.c\
init_game.c\
move.c\
val_utils.c

OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME) : $(OBJS) so_long.h Makefile
	cc $(CFLAGS) $(OBJS) -o $(NAME)  -Lmlx -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re