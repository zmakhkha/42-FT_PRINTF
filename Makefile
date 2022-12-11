NAME = libftprintf.a
SRC = ft_printf_utils.c		ft_printf.c		libft_utils.c ft_calloc.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wextra -Wall -Werror

all: $(NAME) 

$(NAME) : $(OBJ)
	ar -rc	$(NAME) $(OBJ)

%.o : %.c ft_printf.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re	: fclean	all

.PHONY: clean fclean all re