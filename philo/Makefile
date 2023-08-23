CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = philo
SRCS = main.c philo_utils.c check_args_errors.c create_threads.c  init_data_philos.c
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

