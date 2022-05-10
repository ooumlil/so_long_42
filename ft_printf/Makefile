NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_tools1.c \
		  ft_tools2.c \
		  ft_printf.c

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)
$(NAME) : $(OBJECTS) ft_printf.h
	@ar rcs $(NAME) $(OBJECTS)

clean :
	@rm -rf $(OBJECTS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
