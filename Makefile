# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keteo <keteo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 16:19:46 by keteo             #+#    #+#              #
#    Updated: 2024/12/17 13:47:35 by keteo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./src/ft_numbers.c ./src/ft_words.c ./src/ft_printf.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wextra -Werror -Wall

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
					ar rcs $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
				$(RM) $(NAME)

re:		fclean all
		
.Phony: all clean fclean re