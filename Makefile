# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:21:36 by mliew             #+#    #+#              #
#    Updated: 2022/09/17 19:36:16 by mliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
RM		=	rm -rf
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	main.c
OBJS	=	$(SRCS:.c=.o)
LIB42	=	lib42
LDFLAGS	=	-Llib42
LDLIBS	=	-l42
SANITIZE=	-fsanitize=address -g3

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIB42)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME) #$(SANITIZE)

clean:
	make clean -C $(LIB42)

fclean: clean
	make fclean -C $(LIB42)

re: fclean all