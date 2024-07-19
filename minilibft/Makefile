#	Variables
Library	=	minilibft
OUTN		= $(Library).a
NAME		=	$(OUTN)
green=\033[0;32m
reset=\033[0m

# Default rule
all: $(NAME)

# Rule to create library
$(NAME):
		make -C libft
		make -C gnl
		make -C printf
		ar -rc $(NAME) libft/*.o printf/*.o gnl/*.o
		@echo "$(green)The minilibft is created!$(reset)"

# Rule to clean object files
clean:
		@make clean -C libft
		@make clean -C gnl
		@make clean -C printf

# Rule to clean everything
fclean:
		@make fclean -C libft
		@make fclean -C gnl
		@make fclean -C printf
		@rm -f $(NAME)
		@echo "$(green)The minilibft is cleared.$(reset)"
		
# Rule to re-make everything
re: fclean all

# Phony targets
.PHONY: all, clean, fclean, re