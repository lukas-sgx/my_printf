##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

CC = epiclang

CFLAGS = -Wall -Werror

SRC = ./lib/my/my_printf.c \
	./lib/my/core/flags/flag_c.c \
	./lib/my/core/flags/default.c \
	./lib/my/core/flags/flag_id.c \
	./lib/my/core/flags/flag_percent.c \
	./lib/my/core/flags/flag_s.c \
	./lib/my/core/flags/flag_p.c \
	./lib/my/core/flags/flag_n.c \
	./lib/my/core/flags/flag_u.c \
	./lib/my/core/flags/flag_x.c \
	./lib/my/core/flags/flag_o.c \
	./lib/my/core/flags/flag_f.c \
	./lib/my/core/flags/flag_e.c \
	./lib/my/core/flags/flag_b.c \
	./lib/my/core/res/my_putchar.c \
	./lib/my/core/res/my_putwstr.c \
	./lib/my/core/res/my_putwchar.c \
	./lib/my/core/res/my_putstr.c \
	./lib/my/core/res/my_put_nbr.c \
	./lib/my/core/res/my_put_long_nbr.c \
	./lib/my/core/res/my_put_dlong_nbr.c \
	./lib/my/core/res/my_putfloat.c \
	./lib/my/core/res/my_strcpy.c \
	./lib/my/core/res/my_strcmp.c \
	./lib/my/core/res/my_convert_base.c \
	./lib/my/core/res/uint_to_str.c \
	./lib/my/core/res/int_to_str.c \
	./lib/my/core/res/my_strlen.c \
	./lib/my/core/res/my_compute_power_rec.c \
	./lib/my/core/res/my_str_to_word_array.c \
	./lib/my/core/res/my_put_unsigned.c\
	./lib/my/core/res/count_int.c\
	./lib/my/core/formats/display_format_id.c\
	./lib/my/core/formats/display_format_x.c\
	./bonus/flag_s_upper.c

OBJ = $(SRC:.c=.o)
NAME = libmy.a
TEST=unit_tests

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

unit_tests: fclean all
	$(CC) tests/test_my_printf.c $(NAME) --coverage -lcriterion -o $(TEST)

tests_run: unit_tests
	./$(TEST)