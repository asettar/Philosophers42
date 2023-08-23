#include "philo.h"

void	init_data(t_data *data, char **argv)
{
	data->number_of_phil = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->number_of_meals = -1;
	if (argv[5])
		data->number_of_meals = ft_atoi(argv[5]);
	data->left_philos =	 data->number_of_phil;    // only when you have number of meals
	data->start_time = get_time();
}

bool	init_philo(t_philo *philos, t_data *data)
{
	int i;

	i = -1;
	pthread_mutex_init(&data->print, NULL);
	while (++i < data->number_of_phil)
	{

		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].left_meals = data->number_of_meals;
		philos[i].last_meal = get_time();
		if (philos[i].last_meal == -1)
			return (1);
		if (pthread_mutex_init(&philos[i].meal_mutex, NULL))
			return (ft_putstr_fd("pthread_mutex_init function error", 2), 1);
		if (pthread_mutex_init(&philos[i].right_fork, NULL))
			return (ft_putstr_fd("pthread_mutex_init function error", 2), 1);
		// if (pthread_mutex_init(&philos[i].left_meals_mutex, NULL))
		// 	return (ft_putstr_fd("pthread_mutex_init function error", 2), 1);
		philos[i].left_fork = &philos[(i + 1) % data->number_of_phil].right_fork;
	}
	if (create_threads(philos, data))
		return (1);
	return (0);
}