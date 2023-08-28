/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:33:04 by asettar           #+#    #+#             */
/*   Updated: 2023/08/24 01:35:36 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leaks(){
	system("leaks philo");
}
int	main(int ac, char **argv)
{
	t_data	data;
	t_philo	*philos;

	// atexit(leaks);
	if (check_errors(ac, argv))
		return (1);
	if (initialize_data(&data, argv))
		return (1);
	philos = (t_philo *)malloc(sizeof(t_philo) * data.number_of_phil);
	if (!philos)
	{
		destroy_mutexes(&data, 3, NULL, 0);
		return (ft_putstr_fd("Allocation error\n", 2), 1);
	}
	if (initialize_philos(philos, &data))
		return (1);
}
