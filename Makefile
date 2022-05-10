NAME = so_long

NAME_B = so_long_bonus

CFLAGS = -Wall -Wextra -Werror -Imlx

PRINTF = ft_printf/libftprintf.a

SRC =  mandatory/gameplay/free.c \
		mandatory/gameplay/player_position.c \
		mandatory/gameplay/player_moving.c \
		mandatory/gameplay/window_creation.c \
		mandatory/map_checking/check_walls.c \
		mandatory/map_checking/contents.c \
		mandatory/map_checking/gnl_tools.c \
		mandatory/map_checking/gnl.c \
		mandatory/map_checking/map_checking.c \
		mandatory/so_long.c

SRC_B =  bonus/map_checking/gnl.c \
		bonus/map_checking/gnl_tools.c \
		bonus/map_checking/check_walls.c \
		bonus/map_checking/contents.c \
		bonus/map_checking/map_checking.c \
		bonus/gameplay/window_creation.c \
		bonus/gameplay/player_position.c \
		bonus/gameplay/player_moving.c \
		bonus/gameplay/enemy_position.c \
		bonus/gameplay/enemy_moving.c \
		bonus/gameplay/tools.c \
		bonus/gameplay/free.c \
		bonus/so_long_bonus.c

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

$(NAME) : $(OBJ) $(PRINTF) mandatory/so_long.h
	@echo "Making so_long"
	@$(CC) $(OBJ) $(PRINTF) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_B) : $(OBJ_B) $(PRINTF) bonus/so_long_bonus.h
	@echo "Making so_long_bonus"
	@$(CC) $(OBJ_B) $(PRINTF) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

$(PRINTF) :
	@echo "Making ft_printf"
	@make -C ft_printf

all : $(NAME)

bonus : $(NAME_B)

clean :
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_B)
	@make -C ft_printf clean

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_B)
	@make -C ft_printf fclean

re : fclean all