NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -I/usr/include -Iminilibx-linux -O3
SRC = src/main.c src/ft_mlx.c utile/ft_fdf_utile.c get_next_line/get_next_line.c\
get_next_line/get_next_line_utils.c src/ft_init_map.c utile/ft_fdf_utile1.c
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = minilibx-linux 
MINILIBX = $(MINILIBX_DIR)/libmlx.a

OBJ = $(SRC:.c=.o)
TOTAL_FILES := $(words $(SRC))
COMPILED_FILES = 0

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m  # No Color

all: $(LIBFT) $(MINILIBX) $(NAME)

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
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean --silent > /dev/null 2>&1
	@make -C $(MINILIBX_DIR) clean --silent > /dev/null 2>&1

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --silent > /dev/null 2>&1
	@make -C $(MINILIBX_DIR) fclean --silent > /dev/null 2>&1 || true

re: fclean all

.PHONY: all clean fclean re