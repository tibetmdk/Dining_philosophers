/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:34:29 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/14 18:12:15 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit(char *msg)
{
	printf(RED"%s"RST, msg);
	exit(EXIT_FAILURE);
}

long	get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

void	ft_usleep(long ms)
{
	long start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(100);
}

void	print_action(t_philo *philo, char *msg)
{
	long	timestamp;
	
	pthread_mutex_lock(&philo->data->data_mutex);
	if (philo->data->simulation_finished)
	{
		pthread_mutex_unlock(&philo->data->data_mutex);
		return ;
	}
	timestamp = get_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->data_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d %s\n", timestamp, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
