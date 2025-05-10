/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:27:41 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/11 00:44:50 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data)
{
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_number);
	if (!data->philos)
		error_exit("Problem in malloc!");// TODO : use free!!
	data->simulation_finished = 0;
	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->philo_number);
	if (!data->forks)
		error_exit("Problem in malloc!");// TODO : use free!!
	pthread_mutex_init(&data->data_mutex, NULL);
	
}
