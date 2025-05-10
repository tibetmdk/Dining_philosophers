/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:27:55 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/11 00:25:36 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av) // philo 5 800 200 200 [4]
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		error_exit("Problem in malloc!"); // TODO: Don't forget free!!
	if (ac != 5 || ac != 6)
		error_exit("Wrong input!\nUsage is -> philo 5 800 200 200 [4]");
	parse_input(data, av);
}