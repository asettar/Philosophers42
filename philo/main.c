#include "philo.h"

int	main(int ac, char **argv)
{
	t_data	data;
	t_philo	*philos;

	if (check_errors(ac, argv))
		return (1);
	init_data(&data, argv);
	philos = (t_philo *)malloc(sizeof(t_philo) * data.number_of_phil);
	if (!philos)
		return (ft_putstr_fd("Allocation error\n", 2), 1);
	if (init_philo(philos, &data))
		return (1);
}
