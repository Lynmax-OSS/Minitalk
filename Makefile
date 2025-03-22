SOURCES= server.c client.c utils.c

OBJECTS=$(SOURCES:.c=.o)

CC= cc

CFLAGS= -Werror -Wextra -Wall

RM= rm -f


all: $(NAME)

$(NAME): server client

server: server.o utils.o libft libftprintf
		$(CC) $(CFLAGS) server.o utils.o -o server -Llibft -Lft_printf -lft -lftprintf

client: client.o utils.o libft libftprintf
		$(CC) $(CFLAGS) client.o utils.o -o client -Llibft -Lft_printf -lft -lftprintf

libft:
		make -C libft all

libftprintf:
		make -C ft_printf all

clean:
		$(RM) $(OBJECTS)
		make -C libft clean
		make -C ft_printf clean

fclean: clean
		$(RM) server client libft/libft.a ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re ft_printf libft server client