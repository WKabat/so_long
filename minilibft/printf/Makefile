Library = libftprintf
SRC		=	ft_print_char \
			ft_print_str \
			ft_print_percent \
			ft_print_nbr \
			ft_print_hex \
			ft_print_unsigned \
			ft_print_ptr \
			ft_printf \

Compiler	= cc
Flags	= -Wall -Wextra -Werror
OUTN	= $(Library).a
CFILES	= $(SRC:%=%.c)
OFILES	= $(SRC:%=%.o)
NAME	= $(OUTN)
$(NAME):
			$(Compiler) $(Flags) -c $(CFILES) -I./
			ar -rc $(OUTN) $(OFILES)
all:	$(NAME)
clean:
		rm -f $(OFILES)
fclean:	clean
		rm -f $(NAME)
re: fclean all

.PHONY: all, clean, fclean, re