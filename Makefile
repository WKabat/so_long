#	Variables
SRC		= 	main \
						map \
						map_check \
						so_long_utils \
						valid_path \
						draw_map \
						tale_check \

CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
AFLAGS	=	minilibft/minilibft.a minilibx/libmlx.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME	=	so_long
CFILES	=	$(SRC:%=%.c)
OFILES	=	$(SRC:%=%.o)
green=\033[0;32m
reset=\033[0m

%.o: %.c
		$(CC) $(CFLAGS) -Imlx -c $< -o $@

# Rule to create library
minilibft/minilibft.a:
		make -C minilibft
		
minilibx/libmlx.a:
		make -C minilibx

$(NAME): $(OFILES) minilibft/minilibft.a minilibx/libmlx.a
		$(CC) $(CFLAGS) $(OFILES) $(AFLAGS) -o $(NAME)
		@echo "$(green)$(NAME) built successfully.$(reset)"

# Default rule
all:	$(NAME)

# Rule to clean object files
clean:
		@make clean -C minilibft
		rm -f $(OFILES)
		@echo "$(green)Object files cleaned.$(reset)"

# Rule to clean everything
fclean: clean
		@make clean -C minilibx
		@make fclean -C minilibft
		rm -f $(NAME)
		@echo "$(green)$(NAME) cleaned.$(reset)"

# Rule to re-make everything	
re: fclean all

# Phony targets
.PHONY: all, clean, fclean, re