NAME = wolf3d
SRCS_DIR = srcs/
SRCS_LIST = draw_wall.c entry.c init_sdl.c init.c exit.c read_map.c render.c pipe.c physics.c event_router.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS = $(SRCS:.c=.o)
INCL = -I includes/ -I libft/ `sdl2-config --cflags`
FLAGS = -Wall -Wextra -Werror
LIB = `sdl2-config --libs` -L./libft -lft -lm

all: lib $(OBJS) $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ $(INCL)

$(NAME): $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $(LIB) $(OBJS) $(SDL)

# FIXME 2nd warning, just in case
lib:
	@rm -f libft/*
	@cp ~/starnuik/my_libft/libft.a libft/
	@cp ~/starnuik/my_libft/libft.h libft/

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all