#include "philo.h"

bool	invalid_number(char *num)
{
	int	i;
	int	start;

	i = 0;
	if (num[0] == '+' && num[1])
		i++;
	while (num[i] == '0')
		i++;
	start = i;
	while (num[i])
	{
		if (!ft_isdigit(num[i++]))
			return (1);
	}
	if ((i - start > 10) || (i - start == 10
		&& ft_memcmp("2147483647", num + start, 10) < 0))
		return (1);
	return (0);
}

bool	check_errors(int ac, char **argv)
{
	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("INVALID NUMBER OF ARGUMENTS\n", 2);
		return (1);
	}
	argv++;
	while (*argv)
	{
		if (invalid_number(*argv))
		{
			ft_putstr_fd("INVALID INPUTS\n", 2);
				return (1);
		}
		argv++;
	}
	return (0);
}
