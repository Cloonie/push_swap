# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:21:36 by mliew             #+#    #+#              #
#    Updated: 2022/09/16 17:21:19 by mliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
RM		=	rm -rf
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	main.c
OBJS	=	$(SRCS:.c=.o)
LIBFT	=	-Llibft -lft
SANITIZE=	-fsanitize=address -g3

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) #$(SANITIZE)

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME) $(ARCLIB)
	make fclean -C libft

re: fclean all