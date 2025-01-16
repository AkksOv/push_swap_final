NAME = printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_putnbr_fd.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_converthexa.c \
	ft_converthexalong.c \
	ft_printpointer.c \
	ft_putunsigned.c \
	ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Library $(NAME) created!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(DEPS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re