/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:46:50 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/17 14:17:55 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int check_death(t_data *data)
{
    int i;

    pthread_mutex_lock(&data->data_mutex);
    for (i = 0; i < data->philo_number; i++)
    {
        if (get_time() - data->philos[i].last_meal_time > data->time_to_die)
        {
            data->simulation_finished = 1;
            pthread_mutex_unlock(&data->data_mutex);

            pthread_mutex_lock(&data->print_mutex);
            printf("%ld %d died\n",
                   get_time() - data->start_time,
                   data->philos[i].id);
            pthread_mutex_unlock(&data->print_mutex);
            return (1);
        }
    }
    pthread_mutex_unlock(&data->data_mutex);
    return (0);
}

static int check_full(t_data *data)
{
    int i;
    int count = 0;

    if (data->limit_of_meals <= 0)
        return (0);
    pthread_mutex_lock(&data->data_mutex);
    for (i = 0; i < data->philo_number; i++)
        if (data->philos[i].meal_count >= data->limit_of_meals)
            count++;
    if (count == data->philo_number)
        data->simulation_finished = 1;
    pthread_mutex_unlock(&data->data_mutex);
    return (count == data->philo_number);
}

void *monitor(void *arg)
{
    t_data *data = (t_data *)arg;

    while (!check_death(data) && !check_full(data))
        usleep(1000);
    return (NULL);
}