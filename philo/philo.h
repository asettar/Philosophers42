#include "libft/libft.h"
#include <stdbool.h>
#include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int	number_of_phil;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meals;
	long long	start_time;
	bool	phil_dead;
	pthread_mutex_t print;
	pthread_mutex_t phil_deadm;
}	t_data;

typedef struct s_philo
{
	int			id;
	int			number_of_meals;
	long long			last_meal;
	pthread_t	th;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	right_fork;
	pthread_mutex_t *left_fork;
	t_data			*data;
}		t_philo;

bool	check_errors(int ac, char **argv);
long long	get_time();
// void	check_death(t_data *data, t_philo  *philos);
// void	ft_usleep(size_t t_ms);
// void	ft_putstr_fd(char *s, int fd);
// int	ft_isdigit(char c);
// void	print(t_philo * ph, char *s);
