#include "philo.h"

void	check_death(t_data *data, t_philo *philos)
{
	int i;

	while (1)
	{
		i = -1;
		while (++i < data->number_of_phil)
		{
			// pthread_mutex_lock(&philos[i].left_meals_mutex);
			if (!data->left_philos)
				return ;
			pthread_mutex_lock(&philos[i].meal_mutex);
			// pthread_mutex_lock(&philos[i].num_meals);
			if (get_time() - philos[i].last_meal >= data->time_to_die
				&& philos[i].left_meals != 0)
			{
				pthread_mutex_lock(&data->print);
				// printf("%lld\n", get_time() - philos[i].last_meal);
				printf("%lld philosopher number %d died\n", get_time() - data->start_time, philos[i].id);
				return ;
			}
			pthread_mutex_unlock(&philos[i].meal_mutex);
			// pthread_mutex_unlock(&philos[i].num_meals);
		}
		// usleep(10);
	}
}

void	*routine(void *philo)
{
	t_philo *ph;
	
	ph = (t_philo *)philo;
	if (ph->id % 2 == 0)
		ft_usleep(ph->data->time_to_eat / 2);
	while (1)
	{
		pthread_mutex_lock(&ph->right_fork);
		print(ph, "has taken the right fork");
		pthread_mutex_lock(ph->left_fork);
		print(ph, "has taken the left fork");
		pthread_mutex_lock(&ph->meal_mutex);
		ph->last_meal = get_time();
		// printf("%lld::||\n", ph->last_meal - ph->data->start_time);
		pthread_mutex_unlock(&ph->meal_mutex);
		print(ph, "is eating");
		ft_usleep(ph->data->time_to_eat);
		pthread_mutex_unlock(&ph->right_fork);
		pthread_mutex_unlock(ph->left_fork);
		// pthread_mutex_lock(&ph->left_meals_mutex);
		if (ph->data->number_of_meals != -1)
			ph->left_meals--;
		// printf("%d :: %d||\n", ph->id, ph->left_meals);
		if (ph->left_meals == 0)
		{
			ph->data->left_philos--;
			break;
		}
		// pthread_mutex_unlock(&ph->left_meals_mutex);
		print(ph, "is sleeping");
		ft_usleep(ph->data->time_to_sleep);
		print(ph, "is thinking");
	}
	return (ph);
}

bool	create_threads(t_philo *philos, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_phil)
	{
		if (pthread_create(&philos[i].th, NULL, &routine, &philos[i]))
			return (ft_putstr_fd("pthread_create func error", 2), 1);
	}
	i = -1;
	while (++i < data->number_of_phil)
		pthread_detach(philos[i].th);
	check_death(data, philos);
	i = -1;
	while (++i < data->number_of_meals)
	{
		pthread_mutex_destroy(&philos[i].right_fork);
		pthread_mutex_destroy(&philos[i].meal_mutex);
		// pthread_mutex_destroy(&philos[i].right_fork);
	}
	return (0);
}
