/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:25:14 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/18 17:17:58 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	destroy_forks(t_data *data)
{
	int i;

	if (!data || !data->forks || data->philo_number <= 0)
		return ;
	i = -1;
	while (++i < data->philo_number)
		pthread_mutex_destroy(&data->forks[i].fork);
}

static void	destroy_mutexes(t_data *data)
{
	if (data->data_mtx_initialized)
		pthread_mutex_destroy(&data->data_mutex);
	if (data->print_mtx_initialized)
		pthread_mutex_destroy(&data->print_mutex);
}

static void	free_all(t_data *data)
{
	if (!data)
		return ;
	
	destroy_forks(data);
	destroy_mutexes(data);

	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
	if (data->forks)
	{
		free(data->forks);
		data->forks = NULL;
	}
}

void	clean_all(t_data *data)
{
	if (!data)
		return ;
	free_all(data);
	free(data);
}