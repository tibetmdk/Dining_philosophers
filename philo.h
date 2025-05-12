#ifndef PHILO_H
# define PHILO_H

//-- LIBRARIES --//
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

//-- SOME DEFINES --
# define RED		"\033[0;31m"	// red
# define GREEN	"\033[0;32m"	//  green
# define LIGHT_BLUE	"\033[1;34m"	// light blue 
# define RST		"\033[0m"	// reset

# define INT_MAX	2147483647
# define mtx_t		pthread_mutex_t
# define FALSE		0
# define TRUE		1

//-- Structs --
typedef struct s_data t_data;

typedef struct s_fork
{
	mtx_t		fork;
	int			fork_id;
}				t_fork;

typedef struct s_philo
{
	int			id;
	int			is_philo_full;
	int			meal_count;
	int			thread_id;
	long		last_meal_time;
	t_data		*data;
	t_fork		*left_fork;
	t_fork		*right_fork;
}				t_philo;

struct s_data
{
	int			philo_number;
	long		time_to_die;
	long		time_to_sleep;
	long		time_to_eat;
	int			limit_of_meals;
	int			simulation_finished;
	t_philo		*philos;
	t_fork		*forks;
	mtx_t		data_mutex;
};

// -- FUNCTIONS --
void	error_exit(char *msg);
void	parse_input(t_data *data, char **av);
#endif
