CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
SRCS = main.c philo_utils.c check_args_errors.c
OBJS = $(SRCS:.c=.o)
HEADER = philo.h
LIBFT = libft/libft.a

all : $(NAME)
$(NAME) : $(OBJS) 
	make -C libft
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@
# $(LIBFT) :
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ 
clean :
	rm -rf $(OBJS)
	make -C libft clean
fclean : clean
	rm -rf $(NAME)
	make -C libft fclean
re : fclean all

