/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:31:56 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/18 17:30:18 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start_threads(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	data->start_time = get_time();
	i = -1;
	while (++i < data->philo_number)
	{
		data->philos[i].last_meal_time = data->start_time;
		if (pthread_create(&data->philos[i].thread, NULL,
			dinner, &data->philos[i]) != 0)
			error_exit("Failed to create philosopher thread!", data);
	}
	if (pthread_create(&monitor_thread, NULL, monitor, data) != 0)
		error_exit("Failed to create monitor thread!", data);
	i = -1;
	while (++i < data->philo_number)
		pthread_join(data->philos[i].thread, NULL);
	pthread_join(monitor_thread, NULL);
}
