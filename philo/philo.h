#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	int left_philos;
	long long	start_time;
	// bool	phil_dead;
	pthread_mutex_t	left_philos_mutex;
	pthread_mutex_t print;
}	t_data;

typedef struct s_philo
{
	int			id;
	int			left_meals;
	long long			last_meal;
	pthread_t	th;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	right_fork;
	pthread_mutex_t *left_fork;
	pthread_mutex_t left_meals_mutex;
	t_data			*data;
}		t_philo;

bool		check_errors(int ac, char **argv);
long long	get_time();
bool		init_philo(t_philo *philos, t_data *data);
bool		init_data(t_data *data, char **argv);
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *str);
void		ft_usleep(size_t t_ms);
void		check_death(t_data *data, t_philo *philos);
bool		create_threads(t_philo *philos , t_data *data);
void		print(t_philo * ph, char *s);
// void	check_death(t_data *data, t_philo  *philos);
// void	ft_usleep(size_t t_ms);
// void	ft_putstr_fd(char *s, int fd);
// int	ft_isdigit(char c);
