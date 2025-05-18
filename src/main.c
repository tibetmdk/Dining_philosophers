/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:27:55 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/18 17:27:37 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av) // philo 5 800 200 200 [4]
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_exit_minimal("Problem in malloc!", data); // TODO: Don't forget free!!
	if (ac != 5 && ac != 6)
		error_exit_minimal("Wrong input!\nUsage is -> philo 5 800 200 200 [4]", data);
	parse_input(data, av);
	init_data(data);
	start_threads(data);
	clean_all(data);
}