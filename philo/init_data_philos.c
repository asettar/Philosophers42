/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:33:39 by asettar           #+#    #+#             */
/*   Updated: 2023/08/24 02:11:52 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_data *data, int ndata, t_philo *philos, int nphilo)
{
	int	i;

	if (ndata <= 1)
		pthread_mutex_destroy(&data->print);
	if (ndata <= 2)
		pthread_mutex_destroy(&data->left_philo_mutex);
	if (ndata <= 3)
		pthread_mutex_destroy(&data->dead_mutex);
	i = -1;
	while (++i < nphilo)
	{
		pthread_mutex_destroy(&philos[i].meal_mutex);
		pthread_mutex_destroy(&philos[i].right_fork);
		pthread_mutex_destroy(&philos[i].left_meals_mutex);
	}
	free(philos);
}

bool	initialize_data(t_data *data, char **argv)
{
	data->number_of_phil = ft_atoi(argv[1]);
	if (data->number_of_phil == 0)
		return (ft_putstr_fd("INVALID INPUTS\n", 2), 1);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->number_of_meals = -1;
	if (argv[5])
		data->number_of_meals = ft_atoi(argv[5]);
	data->left_philos = data->number_of_phil;
	data->start_time = get_time();
	data->dead_philo = 0;
	if (pthread_mutex_init(&data->print, NULL))
		return (ft_putstr_fd("pthread_mutex_init function error", 2), 1);
	if (pthread_mutex_init(&data->left_philo_mutex, NULL))
	{
		destroy_mutexes(data, 1, NULL, 0);
		return (ft_putstr_fd("pthread_mutex_init function error", 2), 1);
	}
	if (pthread_mutex_init(&data->dead_mutex, NULL))
	{
		destroy_mutexes(data, 2, NULL, 0);
		return (ft_putstr_fd("pthread_mutex_init function error", 2), 1);
	}
	return (0);
}

int	initialize_philo_mutexes(t_philo *philos, int i, t_data *data)
{
	if (pthread_mutex_init(&philos[i].meal_mutex, NULL))
	{
		destroy_mutexes(data, 3, philos, i);
		return (ft_putstr_fd("pthread_mutex_init function error", 2), 1);
	}
	if (pthread_mutex_init(&philos[i].right_fork, NULL))
	{
		pthread_mutex_destroy(&philos[i].meal_mutex);
		destroy_mutexes(data, 3, philos, i);
		return (ft_putstr_fd("pthread_mutex_init function error", 2), 1);
	}
	if (pthread_mutex_init(&philos[i].left_meals_mutex, NULL))
	{
		pthread_mutex_destroy(&philos[i].meal_mutex);
		pthread_mutex_destroy(&philos[i].right_fork);
		destroy_mutexes(data, 3, philos, i);
		return (ft_putstr_fd("pthread_mutex_init function error", 2), 1);
	}
	return (0);
}

bool	initialize_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_phil)
	{
		if (initialize_philo_mutexes(philos, i, data))
			return (1);
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].left_meals = data->number_of_meals;
		philos[i].last_meal = get_time();
		philos[i].left_fork = &philos[(i + 1)
			% data->number_of_phil].right_fork;
	}
	if (create_threads(philos, data))
		return (1);
	return (0);
}
