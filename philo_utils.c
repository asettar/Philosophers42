#include "philo.h"

long long	get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	check_death(t_data *data, t_philo *philos)
{
	int i;
	while (1)
	{
		i = -1;
		while (++i < data->number_of_phil)
		{
			pthread_mutex_lock(&philos[i].meal_mutex);
			if (get_time() - philos[i].last_meal >= data->time_to_die)
			{
				pthread_mutex_lock(&data->print);
				printf("%lld %d %s\n", get_time() - data->start_time, philos[i].id, "died");
				return;
			}
			pthread_mutex_unlock(&philos[i].meal_mutex);
			usleep(10);
		}
	}
}

void ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

int ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

void print(t_philo *ph, char *s)
{
	pthread_mutex_lock(&ph->data->print);
	printf("%lld  ", get_time() - ph->data->start_time);
	printf("philosopher %d %s\n", ph->id, s);
	pthread_mutex_unlock(&ph->data->print);
}