# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 21:11:40 by rcotter-          #+#    #+#              #
#    Updated: 2019/01/19 15:37:06 by mferny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = *.c

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) fillit.h
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -I.	

clean:
	rm -f *.o 
	rm -f *.gch

fclean: clean
	rm -f $(NAME)

re: fclean all
