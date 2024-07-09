SRC		= 	main \

CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g --leak-check=full
AFLAGS	=	minilibx/libmlx.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME	=	so_long
CFILES	=	$(SRC:%=%.c)
OFILES	=	$(SRC:%=%.o)

%.o: %.c
		$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OFILES)
		$(CC) $(CFLAGS) $(OFILES) $(AFLAGS) -o $(NAME)
		@echo "$(NAME) built successfully."

all:	$(NAME)

clean:
		rm -f $(OFILES)
		@echo "Object files cleaned."
fclean: clean
		rm -f $(NAME)
		@echo "Executable cleaned."
re: fclean all

.PHONY: all, clean, fclean, re