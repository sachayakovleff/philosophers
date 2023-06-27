# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 02:23:38 by syakovle          #+#    #+#              #
#    Updated: 2023/06/27 00:40:20 by syakovle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers.a

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIBFT = libft/libft.a
PRINTF = printf/ft_printf.a

FILES	=	philosophers		\
			srcs/init			\
			srcs/threads		\
			srcs/time			\
			srcs/thread_utils	\
			srcs/init_utils

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)
	@make all -C libft
	@make all -C printf
	$(CC) $(CFLAGS) ./philosophers.c  $(NAME) $(PRINTF) $(LIBFT) -o philo

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make clean -C libft
	@make clean -C printf

fclean: clean
	$(RM) $(NAME) philosophers
	@make fclean -C libft
	@make fclean -C printf
	
re: clean all

.PHONY: all clean fclean re
