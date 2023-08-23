#include "philo.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*(str1 + i) != *(str2 + i))
			return (*(str1 + i) - *(str2 + i));
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str)
{
	int	integer;
	int	sign;
	int	i;

	i = 0;
	integer = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		integer = integer * 10 + str[i] - '0';
		i++;
	}
	return (integer * sign);
}

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
