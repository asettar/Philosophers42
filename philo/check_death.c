#include "philo.h"

bool	is_dead_philo(t_philo *philos, int i, t_data *data)
{
	if (get_time() - philos[i].last_meal >= data->time_to_die
		&& philos[i].left_meals)
	{
		pthread_mutex_lock(&data->print);
		printf("%lld philosopher number %d died\n",
			get_time() - data->start_time, philos[i].id);
		pthread_mutex_lock(&data->dead_mutex);
		data->dead_philo = 1;
		pthread_mutex_unlock(&philos[i].meal_mutex);
		pthread_mutex_unlock(&data->dead_mutex);
		return (usleep(100000), 1);
	}
	pthread_mutex_unlock(&philos[i].meal_mutex);
	return (0);
}

void	check_death(t_data *data, t_philo *philos)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->number_of_phil)
		{
			pthread_mutex_lock(&data->left_philo_mutex);
			if (!data->left_philos || !data->number_of_meals)
				return (pthread_mutex_unlock(&data->left_philo_mutex), (void)0);
			pthread_mutex_unlock(&data->left_philo_mutex);
			pthread_mutex_lock(&philos[i].meal_mutex);
			if (is_dead_philo(philos, i, data))
				return ;
		}
	}
}
