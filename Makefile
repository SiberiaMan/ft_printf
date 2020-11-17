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
			value_print.c\
			value_print2.c\

headers	=	ft_printf.h

OBJS	= $(SRC:.c=.o)

B_OBJS	= $(BNS:.c=.o)

$(NAME): $(headers)
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(headers)
	ar rc $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -rf $(OBJS) $(B_OBJS)

fclean: clean
	rm -rf libft.a

re: fclean all

.PHONY:		all clean fclean re
