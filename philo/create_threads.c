/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:44:12 by asettar           #+#    #+#             */
/*   Updated: 2023/08/24 02:10:22 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_data *data, t_philo *philos)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->number_of_phil)
		{
			pthread_mutex_lock(&data->left_philo_mutex);
			if (!data->left_philos)
				return (pthread_mutex_unlock(&data->left_philo_mutex), (void)0);
			pthread_mutex_unlock(&data->left_philo_mutex);
			pthread_mutex_lock(&philos[i].meal_mutex);
			if (time_(philos[i]) >= data->time_to_die && philos[i].left_meals)
			{
				pthread_mutex_lock(&data->print);
				printf("%lld philosopher number %d died\n",
					get_time() - data->start_time, philos[i].id);
				pthread_mutex_lock(&data->dead_mutex);
				data->dead_philo = 1;
				pthread_mutex_unlock(&data->dead_mutex);
				return (sleep(1), (void)0);
			}
			pthread_mutex_unlock(&philos[i].meal_mutex);
		}
	}
}

void	eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->right_fork);
	print(ph, "has taken the right fork");
	pthread_mutex_lock(ph->left_fork);
	print(ph, "has taken the left fork");
	pthread_mutex_lock(&ph->meal_mutex);
	ph->last_meal = get_time();
	pthread_mutex_unlock(&ph->meal_mutex);
	print(ph, "is eating");
	ft_usleep(ph->data->time_to_eat);
	pthread_mutex_unlock(&ph->right_fork);
	pthread_mutex_unlock(ph->left_fork);
}

void	sleep_think(t_philo *ph)
{
	print(ph, "is sleeping");
	ft_usleep(ph->data->time_to_sleep);
	print(ph, "is thinking");
}

void	*routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->id % 2 == 0)
		ft_usleep(ph->data->time_to_eat / 2);
	while (1)
	{
		pthread_mutex_lock(&ph->data->dead_mutex);
		if (ph->data->dead_philo)
			return (pthread_mutex_unlock(&ph->data->dead_mutex), ph);
		pthread_mutex_unlock(&ph->data->dead_mutex);
		eat(ph);
		if (ph->data->number_of_meals != -1)
			ph->left_meals--;
		if (ph->left_meals == 0)
		{
			pthread_mutex_lock(&ph->data->left_philo_mutex);
			ph->data->left_philos--;
			pthread_mutex_unlock(&ph->data->left_philo_mutex);
			break ;
		}
		sleep_think(ph);
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
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->left_philo_mutex);
	i = -1;
	while (++i < data->number_of_meals)
	{
		pthread_mutex_destroy(&philos[i].right_fork);
		pthread_mutex_destroy(&philos[i].meal_mutex);
		pthread_mutex_destroy(&philos[i].left_meals_mutex);
	}
	free(philos);
	return (0);
}
