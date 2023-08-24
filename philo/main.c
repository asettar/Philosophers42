/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:33:04 by asettar           #+#    #+#             */
/*   Updated: 2023/08/24 01:00:30 by asettar          ###   ########.fr       */
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

	atexit(leaks);
	if (check_errors(ac, argv))
		return (1);
	if (init_data(&data, argv))
		return (1);
	philos = (t_philo *)malloc(sizeof(t_philo) * data.number_of_phil);
	if (!philos)
		return (ft_putstr_fd("Allocation error\n", 2), 1);
	if (init_philo(philos, &data))
		return (1);
}
