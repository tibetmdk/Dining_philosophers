/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:00:40 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/14 17:55:25 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int is_simulation_finished(t_philo *philo)
{
    int finished;

    pthread_mutex_lock(&philo->data->data_mutex);
    finished = philo->data->simulation_finished;
    pthread_mutex_unlock(&philo->data->data_mutex);

    return (finished);
}

static void stagger_start(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2); // çakışma olursa deneme yap
}

static	int philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(&philo->right_fork->fork);
	print_action(philo, "has taken a fork");
	
	pthread_mutex_lock(&philo->data->data_mutex);
	philo->last_meal_time = get_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->data->data_mutex);

	print_action(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	
	pthread_mutex_unlock(&philo->left_fork->fork);
	pthread_mutex_unlock(&philo->right_fork->fork);
	return (0);
}

static void sleep_and_think(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
	print_action(philo, "is thinking");
}

void *dinner(void *data)
{
    t_philo *philo;

	philo = (t_philo *)data;
    stagger_start(philo);

    while (!is_simulation_finished(philo))
    {
        philo_eat(philo);
		
        if (philo->data->limit_of_meals > 0)
        {
            pthread_mutex_lock(&philo->data->data_mutex);
            if (philo->meal_count >= philo->data->limit_of_meals)
            {
                philo->is_philo_full = TRUE;
                pthread_mutex_unlock(&philo->data->data_mutex);
                break;
            }
            pthread_mutex_unlock(&philo->data->data_mutex);
        }

        sleep_and_think(philo);
    }
    return (NULL);
}
