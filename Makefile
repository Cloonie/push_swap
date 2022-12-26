# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:21:36 by mliew             #+#    #+#              #
#    Updated: 2022/12/27 00:44:23 by mliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
RM		=	rm -rf
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	mandatory.c operators.c init.c validation.c sort.c print.c help.c sort3.c large.c
OBJS	=	$(SRCS:.c=.o)

BSRCS	=	bonus.c operators.c init.c validation.c sort.c print.c help.c sort3.c large.c
BOBJS	=	$(BSRCS:.c=.o)

LIB42	=	lib42
LDFLAGS	=	-Llib42
LDLIBS	=	-lft
SANITIZE=	-fsanitize=address -g3

all: $(NAME) checker

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

mandatory $(NAME): $(OBJS)
	make -C $(LIB42)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME) #$(SANITIZE)

bonus checker: $(BOBJS)
	make -C $(LIB42)
	$(CC) $(CFLAGS) $(BOBJS) $(LDFLAGS) $(LDLIBS) -o checker #$(SANITIZE)

clean:
	make clean -C $(LIB42)

fclean: clean
	make fclean -C $(LIB42)
	$(RM) push_swap *.o

re: fclean all