/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:36:36 by asettar           #+#    #+#             */
/*   Updated: 2023/08/24 00:37:10 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(size_t t_ms)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < t_ms)
	{
		usleep(50);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

void	print(t_philo *ph, char *s)
{
	pthread_mutex_lock(&ph->data->print);
	printf("%lld  ", get_time() - ph->data->start_time);
	printf("philosopher %d %s\n", ph->id, s);
	pthread_mutex_unlock(&ph->data->print);
}

long long	time_(t_philo ph)
{
	return (get_time() - ph.last_meal);
}
