NAME = libftprintf.a
SRC = f_printf/libftprintf.c

OBJ = $(SRC:.c=.o)


CC = cc

CFLAGS = -Wextra -Wall -Werror

all: $(NAME) libft

$(NAME) : $(OBJ) libft
	ar -rc	$(NAME) $(OBJ) libft/libft.a

%.o : %.c libftprintf.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re	: fclean	all

libft:	
	$(MAKE) -C libft