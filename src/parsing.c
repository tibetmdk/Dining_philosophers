/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:18:21 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/18 17:23:24 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
static const char *valid_input(const char *str, t_data *data)
{
	int			len;
	const char	*number;

	len = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		error_exit_minimal("Feed me only positive values", data);
	if (!is_digit(*str))
		error_exit_minimal("The input is not a correct digit", data);
	number = str;
	while (is_digit(*str++))
		++len;
	if (len > 10)
		error_exit_minimal("The value is too big, INT_MAX is the limit", data);
	return (number);
}

static long	ft_atol(const char *str, t_data *data)
{
	long	num;

	num = 0;
	str= valid_input(str, data);
	while (is_digit(*str))
		num = (num * 10) + (*str++ - '0');
	if (num > INT_MAX)
	error_exit_minimal("The value is too big, INT_MAX is the limit", data);
	return (num);
}

void	parse_input(t_data *data, char **av)
{
	data->philo_number = ft_atol(av[1], data);
	data->time_to_die = ft_atol(av[2], data);
	data->time_to_eat = ft_atol(av[3], data);
	data->time_to_sleep = ft_atol(av[4], data);
	if (data->time_to_die < 60
		|| data->time_to_eat < 60
		|| data->time_to_sleep < 60)
		error_exit_minimal("Use timestamps major than 60ms", data);
	if (av[5])
		data->limit_of_meals = ft_atol(av[5], data);
	else
		data->limit_of_meals = -1;
}