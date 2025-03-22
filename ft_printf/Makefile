# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 16:19:46 by keteo             #+#    #+#              #
#    Updated: 2025/03/20 16:50:36 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_numbers.c ft_words.c ft_printf.c

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