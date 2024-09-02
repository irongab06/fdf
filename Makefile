NAME = fdf
BONUS_NAME = fdf_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/include -Iminilibx-linux -O3
SRC = src/main.c src/ft_mlx.c utile/ft_fdf_utile.c get_next_line/get_next_line.c\
get_next_line/get_next_line_utils.c src/ft_init_map.c utile/ft_fdf_utile1.c\
utile/ft_fdf_utile2.c utile/ft_fdf_utile3.c\
utile/ft_fdf_utile4.c utile/ft_fdf_utile5.c utile/ft_fdf_utile6.c
OBJ = $(SRC:.c=.o)
SRC_BONUS = src_bonus/main.c src_bonus/ft_mlx.c utile_bonus/ft_fdf_utile.c get_next_line/get_next_line.c\
get_next_line/get_next_line_utils.c src_bonus/ft_init_map.c utile_bonus/ft_fdf_utile1.c\
utile_bonus/ft_fdf_utile2.c utile_bonus/ft_fdf_utile3.c src_bonus/ft_mlx_utile.c\
utile_bonus/ft_fdf_utile4.c utile_bonus/ft_fdf_utile5.c utile_bonus/ft_fdf_utile6.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = minilibx-linux 
MINILIBX = $(MINILIBX_DIR)/libmlx.a

OBJ_BONUS = $(SRC_BONUS:.c=.o)
TOTAL_FILES := $(words $(SRC))
COMPILED_FILES = 0

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m  # No Color

all: $(LIBFT) $(MINILIBX) $(NAME)
bonus: $(LIBFT) $(MINILIBX) $(BONUS_NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -L$(MINILIBX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
		@echo "${GREEN}"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣾⠋⠉⠉⠉⢻⣷⣶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡿⠛⠁⠸⡆⠀⠀⠀⢸⠀⠈⠙⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⣧⠀⠀⢀⡟⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿⡇⠀⠀⠀⠘⠦⠤⠼⠁⠀⠀⠀⣸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣇⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⢰⠋⢹⡀⠀ ⣰⠋⠁⣷⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣄⣀⡀⠀⠀⠀⠀⢀⣀⣀⣼⣽⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣯⣤⣼⡇⠀⣼⡷⢤⣴⠇⠀⠀⢀⣀⡀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠈⠓⠾⠿⠛⠛⠉⠙⠛⠛⠒⠋⣸⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡏⠛⢻⠇⣼⠉⠛⢛⡟⠀⣠⠞⠉⢸⠇⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢳⣀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠿⣿⢿⣶⢻⣝⣿⡾⣠⠚⣿⣿⣶⠋⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡄⢻⣣⡀⠀⠀⠀⠀⠀⢠⣾⢃⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣶⣶⣾⢿⣦⣤⣼⡿⣿⣷⣤⠟⠁⢀⣠⠤⠶⣦"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣷⢈⣧⣳⡤⠤⢤⠤⣴⣿⣇⣼⢿⣻⣿⠿⢶⣦⣄⠀⠀⠀⠀⠀⠀⢀⡾⡟⠶⣄⠀⡼⠀⠙⣍⠀⢀⠉⡉⠙⣷⣤⣽⣯⣴⠚⢿⣿⣦⠴⠋"
	@echo "⠀⠀⠀⠀⠀⠀⢀⣠⡤⠤⢤⡴⣚⣽⣿⣿⣧⣭⠧⠖⠒⠶⢿⣴⣿⣟⠛⠉⣩⡶⠾⠟⣛⡿⠶⠖⠒⠒⠒⠶⣧⡁⣠⢛⡿⣥⣈⣢⡼⠋⠉⠉⠳⣄⠀⠉⣏⠘⢿⣷⠼⠋⠁⠀⠀"
	@echo "⠀⠀⠀⢀⣠⠞⠉⢀⣠⠴⠛⠻⣿⣿⣯⣟⣻⣴⣶⠿⠟⠛⠉⠙⠻⢬⡉⡟⠁⢀⡴⠚⠁⠀⠀⠀⠀⠀⠀⠀⠈⣻⡛⢋⣠⣿⠋⢻⠀⠀42⠀⢸⠒⠁⠙⢿⠉⠀⠀⠀⠀⠀⠀"
	@echo "⠀⣰⠟⣿⡁⠀⠴⠛⠁⠀⠀⢠⣌⠻⣶⡶⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⣶⣿⣦⣤⣶⡾⠿⡿⠟⣻⣷⣶⡶⠋⢿⠛⠛⠁⠀⠈⠣⣄⣀⣀⡴⠛⠢⠤⣤⡟⠀⠀⠀⠀⠀⠀⠀"
	@echo "⢰⠇⣠⡾⠃⠀⠀⠀⠀⠀⠀⠸⣯⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⡿⣲⣿⠃⠀⡜⠁⣰⡿⣿⠋⠀⣰⣿⣇⠀⠀⠀⣀⠀⠀⠉⡁⠀⠀⠀⣰⠟⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣼⢠⡿⠀⠀⠀⢠⣤⣤⣤⣤⣤⣤⣤⣤⣄⣠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣭⣿⣿⡇⠀⣼⠁⢰⣿⣿⡏⠀⢠⣿⣾⣿⣟⡛⠉⠁⠀⠀⠀⠱⢤⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⢸⡇⠀⠀⠀⠈⢷⠀⠀  ⠀⠀⣀⠴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⡀⣀⣯⣀⣾⣿⣿⣷⠦⣤⣳⣸⡻⣧⡉⢿⣷⣶⣶⣶⣶⣾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣿⡇⠀⠀⠀⠀⠈⢧⠀  ⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠛⣿⣯⡻⣿⣿⣿⣿⣿⡿⢿⣿⣦⡙⣿⣽⣾⣎⣙⣛⣻⣿⣩⣾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠸⣿⡇⠀⠀⠀⠀⠀⠈⣇⡤⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⠿⠟⠛⢻⡟⠛⣳⣿⣿⣿⣿⣿⣦⣙⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⢠⣏⣧⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣼⡷⡄⠀⠀⠸⣷⣾⡿⢿⣴⣿⣿⡟⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⢸⣿⡟⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⠟⣛⡧⠖⠛⣦⡀⣶⣿⣿⠿⣿⡿⢻⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣾⣿⣇⠸⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠁⠈⠙⢉⣡⠴⢾⣯⣽⠿⣿⣿⣿⣷⣄⣠⣾⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⡇⣿⣿⠀⠹⣤⣶⡖⣒⠚⠒⠲⢦⡀⠀⠀⡴⠁⠀⠀⢀⡴⠋⠉⠛⠛⠋⠁⣶⡼⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣇⣿⣿⡆⣠⣿⣿⣧⣸⣷⠀⠀⣸⠉⠳⣾⠁⠀⢀⡴⠋⠀⠀⢀⣤⣶⣶⣾⡿⠁⢹⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠁⠉⠉⠁⠀⠈⠀⠉⠉⠘⠁⠀⠀⢀⠀⠈⠁⠀⠈⠀⠀⠀⠀⠀⢁⣁⠀⠀⠀⠀⠀⠈⠉⠁⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${NC}"

$(BONUS_NAME): $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -L$(MINILIBX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(BONUS_NAME)
	@echo "${GREEN}"
		@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣾⠋⠉⠉⠉⢻⣷⣶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡿⠛⠁⠸⡆⠀⠀⠀⢸⠀⠈⠙⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⣧⠀⠀⢀⡟⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿⡇⠀⠀⠀⠘⠦⠤⠼⠁⠀⠀⠀⣸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣇⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⢰⠋⢹⡀⠀ ⣰⠋⠁⣷⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣄⣀⡀⠀⠀⠀⠀⢀⣀⣀⣼⣽⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣯⣤⣼⡇⠀⣼⡷⢤⣴⠇⠀⠀⢀⣀⡀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠈⠓⠾⠿⠛⠛⠉⠙⠛⠛⠒⠋⣸⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡏⠛⢻⠇⣼⠉⠛⢛⡟⠀⣠⠞⠉⢸⠇⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢳⣀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠿⣿⢿⣶⢻⣝⣿⡾⣠⠚⣿⣿⣶⠋⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡄⢻⣣⡀⠀⠀⠀⠀⠀⢠⣾⢃⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣶⣶⣾⢿⣦⣤⣼⡿⣿⣷⣤⠟⠁⢀⣠⠤⠶⣦"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣷⢈⣧⣳⡤⠤⢤⠤⣴⣿⣇⣼⢿⣻⣿⠿⢶⣦⣄⠀⠀⠀⠀⠀⠀⢀⡾⡟⠶⣄⠀⡼⠀⠙⣍⠀⢀⠉⡉⠙⣷⣤⣽⣯⣴⠚⢿⣿⣦⠴⠋"
	@echo "⠀⠀⠀⠀⠀⠀⢀⣠⡤⠤⢤⡴⣚⣽⣿⣿⣧⣭⠧⠖⠒⠶⢿⣴⣿⣟⠛⠉⣩⡶⠾⠟⣛⡿⠶⠖⠒⠒⠒⠶⣧⡁⣠⢛⡿⣥⣈⣢⡼⠋⠉⠉⠳⣄⠀⠉⣏⠘⢿⣷⠼⠋⠁⠀⠀"
	@echo "⠀⠀⠀⢀⣠⠞⠉⢀⣠⠴⠛⠻⣿⣿⣯⣟⣻⣴⣶⠿⠟⠛⠉⠙⠻⢬⡉⡟⠁⢀⡴⠚⠁⠀⠀⠀⠀⠀⠀⠀⠈⣻⡛⢋⣠⣿⠋⢻⠀⠀42⠀⢸⠒⠁⠙⢿⠉⠀⠀⠀⠀⠀⠀"
	@echo "⠀⣰⠟⣿⡁⠀⠴⠛⠁⠀⠀⢠⣌⠻⣶⡶⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⣶⣿⣦⣤⣶⡾⠿⡿⠟⣻⣷⣶⡶⠋⢿⠛⠛⠁⠀⠈⠣⣄⣀⣀⡴⠛⠢⠤⣤⡟⠀⠀⠀⠀⠀⠀⠀"
	@echo "⢰⠇⣠⡾⠃⠀⠀⠀⠀⠀⠀⠸⣯⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⡿⣲⣿⠃⠀⡜⠁⣰⡿⣿⠋⠀⣰⣿⣇⠀⠀⠀⣀⠀⠀⠉⡁⠀⠀⠀⣰⠟⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣼⢠⡿⠀⠀⠀⢠⣤⣤⣤⣤⣤⣤⣤⣤⣄⣠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣭⣿⣿⡇⠀⣼⠁⢰⣿⣿⡏⠀⢠⣿⣾⣿⣟⡛⠉⠁⠀⠀⠀⠱⢤⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⢸⡇⠀⠀⠀⠈⢷⠀⠀  ⠀⠀⣀⠴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⡀⣀⣯⣀⣾⣿⣿⣷⠦⣤⣳⣸⡻⣧⡉⢿⣷⣶⣶⣶⣶⣾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣿⡇⠀⠀⠀⠀⠈⢧⠀  ⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠛⣿⣯⡻⣿⣿⣿⣿⣿⡿⢿⣿⣦⡙⣿⣽⣾⣎⣙⣛⣻⣿⣩⣾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠸⣿⡇⠀⠀⠀⠀⠀⠈⣇⡤⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⠿⠟⠛⢻⡟⠛⣳⣿⣿⣿⣿⣿⣦⣙⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⢠⣏⣧⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣼⡷⡄⠀⠀⠸⣷⣾⡿⢿⣴⣿⣿⡟⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⢸⣿⡟⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⠟⣛⡧⠖⠛⣦⡀⣶⣿⣿⠿⣿⡿⢻⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣾⣿⣇⠸⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠁⠈⠙⢉⣡⠴⢾⣯⣽⠿⣿⣿⣿⣷⣄⣠⣾⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⡇⣿⣿⠀⠹⣤⣶⡖⣒⠚⠒⠲⢦⡀⠀⠀⡴⠁⠀⠀⢀⡴⠋⠉⠛⠛⠋⠁⣶⡼⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣇⣿⣿⡆⣠⣿⣿⣧⣸⣷⠀⠀⣸⠉⠳⣾⠁⠀⢀⡴⠋⠀⠀⢀⣤⣶⣶⣾⡿⠁⢹⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠁⠉⠉⠁⠀⠈⠀⠉⠉⠘⠁⠀⠀⢀⠀⠈⠁⠀⠈⠀⠀⠀⠀⠀⢁⣁⠀⠀⠀⠀⠀⠈⠉⠁⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${NC}"

.c.o:
	$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
	@$(CC) $(CFLAGS) -c $< -o $@
	@PROGRESS=$$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES))); \
	BAR=$$(( $(COMPILED_FILES) * 50 / $(TOTAL_FILES) )); \
	BAR_GRAPH=""; \
	i=0; \
	while [ $$i -lt $$BAR ]; do \
		BAR_GRAPH=$${BAR_GRAPH}/; \
		i=$$((i + 1)); \
	done; \
	i=$$((50 - $$BAR)); \
	while [ $$i -gt 0 ]; do \
		BAR_GRAPH="$${BAR_GRAPH} "; \
		i=$$((i - 1)); \
	done; \
	if [ $$PROGRESS -eq 100 ]; then \
		tput cuu1; tput el; echo "Compiling: [  ${GREEN}$$BAR_GRAPH${NC}] $$PROGRESS%"; \
	else \
		tput cuu1; tput el; echo  "Compiling: [  ${RED}$$BAR_GRAPH${NC}] $$PROGRESS%"; \
	fi

$(LIBFT):
	@make -C $(LIBFT_DIR) --silent > /dev/null 2>&1

$(MINILIBX):
	@make -C $(MINILIBX_DIR) --silent > /dev/null 2>&1

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)
	@make -C $(LIBFT_DIR) clean --silent > /dev/null 2>&1
	@make -C $(MINILIBX_DIR) clean --silent > /dev/null 2>&1

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean --silent > /dev/null 2>&1
	@make -C $(MINILIBX_DIR) fclean --silent > /dev/null 2>&1 || true

re: fclean all
rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus