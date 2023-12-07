/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 08:59:10 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/07 21:55:25 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

typedef struct s_vars
{
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					nb_meals;
	unsigned long long	last_meal;
}	t_vars;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_p;
	pthread_t		overwatch;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	t_vars			v;
	unsigned long	start;
	int				is_dead;
}	t_philo;

#endif
