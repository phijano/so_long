NAME = so_long
LIB = lib$(NAME).a

MAIN = so_long.c

SOURCES = \
		check_args.c check_map.c  init_game.c load_sprites.c load_font.c	\
		input.c update_game.c update_hero.c move_hero.c move_enemies.c		\
		draw.c draw_score.c draw_hero_enemy.c exit_game.c free_memory.c

MAINOBJECT = $(MAIN:.c=.o)
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LIBS = -L. -l$(NAME) -lmlx -lft
LINKS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(MAINOBJECT) $(OBJECTS)
	make -C minilibx_opengl_20191021
	mv minilibx_opengl_20191021/libmlx.a .
	make bonus -C libft
	mv libft/libft.a .
	ar -rcs $(LIB) $(OBJECTS)
	$(CC) -o $(NAME) $(CFLAGS) $(MAINOBJECT) $(LIBS) $(LINKS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(LIB) $(MAINOBJECT) $(OBJECTS)
	make clean -C minilibx_opengl_20191021
	rm -f libmlx.a
	make clean -C libft
	rm -f libft.a

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
