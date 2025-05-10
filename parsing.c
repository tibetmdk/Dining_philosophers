#include "philo.h"

static	int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || 32 == c)
		return (1);
	return (0);
}

static int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
static const char *valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		error_exit("Feed me only positive values");
	if (!is_digit(*str))
		error_exit("The input is not a correct digit");
	number = str;
	while (is_digit(*str++))
		++len;
	if (len > 10)
		error_exit("The value is too big, INT_MAX is the limit");
	return (number);
}

static long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str= valid_input(str);
	while (is_digit(*str))
		num = (num * 10) + (*str++ - '0');
	if (num > INT_MAX)
	error_exit("The value is too big, INT_MAX is the limit");
	return (num);
}

void	parse_input(t_data *data, char **av)
{
	data->philo_number = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]) * 1000;
	data->time_to_eat = ft_atol(av[3]) * 1000;
	data->time_to_sleep = ft_atol(av[4]) * 1000;
	if (data->time_to_die < 60000
		|| data->time_to_eat < 60000
		|| data->time_to_sleep < 60000)
		error_exit("Use timestamps major than 60ms");
	if (av[5])
		data->limit_of_meals = ft_atol(av[5]);
	else
		data->limit_of_meals = -1;
}