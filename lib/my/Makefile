##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

CC = epiclang

CFLAGS = -Wall -Iinclude

SRC = my_printf.c \
	./core/flags/char.c \
	./core/flags/default.c \
	./core/flags/int.c \
	./core/flags/percent.c \
	./core/flags/string.c \
	./core/flags/pointer.c \
	./core/flags/flag_n.c \
	./core/flags/flag_u.c \
	./core/flags/flag_x.c \
	./core/flags/flag_o.c \
	./core/res/my_putchar.c \
	./core/res/my_putstr.c \
	./core/res/my_put_nbr.c \
	./core/res/my_strcpy.c \
	./core/res/my_strcmp.c \
	./core/res/my_convert_base.c \
	./core/res/uint_to_str.c \
	./core/res/my_put_unsigned.c

OBJ = $(SRC:.c=.o)
NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ..

%.o: .%c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
