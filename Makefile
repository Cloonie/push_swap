# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:21:36 by mliew             #+#    #+#              #
#    Updated: 2022/12/29 16:15:20 by mliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
RM		=	rm -rf
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRC	=	mandatory.c operators.c init.c validation.c helper.c sort3.c large.c print.c
OBJS	=	$(SRC:.c=.o)

BSRC	=	bonus.c operators.c init.c validation.c helper.c sort3.c large.c print.c
BOBJS	=	$(BSRC:.c=.o)

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
	$(RM) push_swap checker *.o

re: fclean all