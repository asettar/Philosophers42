#include "philo.h"

// void error_exit(char *s)
// {
// 	ft_putstr_fd(s, 2);
// 	exit(EXIT_FAILURE);
// }

// void	ft_usleep(size_t t_ms)
// {
// 	size_t start;

// 	start = get_time();
// 	while (get_time() - start < t_ms)
// 	{
// 		usleep(100);
// 	}
// }

bool	init_data(t_data *data, char **argv)
{
	data->number_of_phil = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->number_of_meals = -1;
	if (argv[5])
		data->number_of_meals = ft_atoi(argv[5]);
	data->start_time = get_time();
	if (data->start_time == -1)
		return(1);
	return (0);
}

// void *routine(void *philo)
// {
// 	t_philo *ph = (t_philo *)philo;
// 	// t_philo ph = philo;
// 	if (ph->id % 2 == 0)
// 		ft_usleep(ph->data->time_to_eat);
// 	while (1)
// 	{
// 		pthread_mutex_lock(&ph->right_fork);
// 		print(ph, "has taken the forks");
// 		pthread_mutex_lock(ph->left_fork);
// 		print(ph, "has taken the forks");
// 		pthread_mutex_lock(&ph->meal_mutex);
// 		ph->last_meal = get_time();
// 		pthread_mutex_unlock(&ph->meal_mutex);
// 		print(ph, "is eating");
// 		ft_usleep(ph->data->time_to_eat);
// 		pthread_mutex_unlock(&ph->right_fork);
// 		pthread_mutex_unlock(ph->left_fork);
// 		print(ph, "is sleeping");
// 		ft_usleep(ph->data->time_to_sleep);
// 		print(ph, "is thinking");
// 	}
// 	return (NULL);
// }

// // dead , print
// bool init_philo(t_philo *philos, t_data *data)
// {
// 	int i;

// 	i = -1;
// 	philos = (t_philo *)malloc(sizeof(t_philo) * data->number_of_phil);
// 	if (!philos)
// 		return (1);
// 	pthread_mutex_init(&data->print, NULL);
// 	while (++i < data->number_of_phil)
// 	{

// 		philos[i].id = i + 1;
// 		philos[i].number_of_meals = 0;
// 		philos[i].data = data;
// 		philos[i].last_meal = get_time();
// 		// return 0;
// 		pthread_mutex_init(&philos[i].meal_mutex, NULL);
// 		pthread_mutex_init(&philos[i].right_fork, NULL);
// 		philos[i].left_fork = &philos[(i + 1) % data->number_of_phil].right_fork;
// 	}
 
// 	i = -1;
// 	while (++i < data->number_of_phil)
// 	{
// 		if (pthread_create(&philos[i].th, NULL, &routine, &philos[i]))
// 			return 1;
// 	}
// 	i = -1;
// 	while (++i < data->number_of_phil)
// 		pthread_detach(philos[i].th);
// 	check_death(data, philos);
// 	return (0);
// }

int main(int ac, char **argv)
{

	t_data data;
	// t_philo philos;

	if (check_errors(ac, argv))
		return (1);
	if (init_data(&data, argv))
		return (1);
	// if (init_philo(&philos, data))
	// 	return (1);
}
