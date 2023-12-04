/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:34:53 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/04 12:52:48 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

typedef struct s_timings
{
	int	die;
	int	eat;
	int	sleep;
	int	nb_meals;
}	t_timings;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	pthread_t			tracker;	
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_timings			timings;
	unsigned long long	last_meal;
	int					is_dead;
}	t_philo;

#endif
