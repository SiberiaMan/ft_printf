NAME	=	libftprintf.a

SRC		=	check_arg.c\
			flag_war.c\
			free_memory.c\
			ft_atoif.c\
			ft_printf.c\
			get_arguments.c\
			itoa_functions.c\
			memsetting.c\
			parser.c\
			print.c\
			print_pointer.c\
			print_processing.c\
			ptr_init.c\
			str_functions.c\
			string_print.c\
			value_print1.c\
			value_print2.c\

HRDS	=	ft_printf.h

OBJS	= $(SRC:.c=.o)

$(NAME): $(HDRS)
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(HDRS)
	ar rc $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf libftprintf.a

re: fclean all

.PHONY:		all clean fclean re
