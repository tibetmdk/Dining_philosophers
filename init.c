/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:27:41 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/14 14:37:20 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assigning_forks(t_philo *philo, t_fork *forks, int position)
{
	int	philo_nbr;

	philo_nbr = philo->data->philo_number;
	philo->right_fork = &forks[(position + 1) % philo_nbr];
	philo->left_fork = &forks[position];
}

static void	init_philos(t_data *data)
{
	int		i;
	t_philo	*philo;
	
	i = -1;
	while (++i < data->philo_number)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->is_philo_full = FALSE;
		philo->meal_count = 0;
		philo->data = data;
		assigning_forks(philo, data->forks, i);
	}	
}

void	init_data(t_data *data)
{
	int	i;

	i = -1;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_number);
	if (!data->philos)
		error_exit("Problem in malloc!");// TODO : use free!!
	data->simulation_finished = 0;
	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->philo_number);
	if (!data->forks)
		error_exit("Problem in malloc!");// TODO : use free!!
	pthread_mutex_init(&data->data_mutex, NULL);
	while (++i < data->philo_number)
	{
		if (pthread_mutex_init(&data->forks[i].fork, NULL) != 0)
			error_exit("Mutex init failed!");
		data->forks[i].fork_id = i;
	}
	init_philos(data);
}
