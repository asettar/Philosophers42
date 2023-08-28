# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asettar <asettar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 01:15:58 by asettar           #+#    #+#              #
#    Updated: 2023/08/24 01:16:06 by asettar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
NAME = philo
SRCS = main.c philo_utils.c check_args_errors.c create_threads.c  init_data_philos.c check_death.c
OBJS = $(SRCS:.c=.o)
HEADER = philo.h
LIBFT = libft/libft.a

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
# $(LIBFT) :
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ 
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all

