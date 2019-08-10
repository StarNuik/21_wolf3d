NAME = wolf3d
SRCS_DIR = srcs/
SRCS_LIST = mouse.c spritequeue.c ai_test.c read_object.c read_enemy.c enemy.c astar.c astar2.c astar3.c object_destroyable.c weapon_raycast.c player_pickup.c player_weapon.c draw_weapon.c draw_gui.c aux.c player_movement.c normalize_fps.c draw_bg.c draw_gui_bg.c draw_sprite.c read_audio.c audio.c raycast.c draw_wall.c entry.c init_sdl.c init.c exit.c read_textures.c read_map.c render.c pipe.c player.c event_router.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS = $(SRCS:.c=.o)
DEPENDS = $(patsubst %.c, %.d, $(SRCS))
INCL = -I includes/ -I libft/ -I SDL2/includes/
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
LIB = -L SDL2/ -lSDL2 -L libft/ -lft -lm
FRAMEWORK = -framework OpenGL -framework AppKit -framework Cocoa

all: lib $(OBJS) $(NAME)
	@echo "\033[32mCompilation finished!\033[39m"

-include $(DEPENDS)

%.o: %.c
	@gcc $(FLAGS) -MMD -MP -c $< -o $@ $(INCL)

$(NAME): $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIB) $(SDL) $(FRAMEWORK)

lib:
	@make -C libft/

clean:
	@rm -f $(OBJS)
	@rm -f $(DEPENDS)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
