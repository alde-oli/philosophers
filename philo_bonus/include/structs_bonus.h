/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 08:59:10 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/08 14:13:48 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include <pthread.h>
# include <semaphore.h>

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
	pthread_t		overwatch;
	sem_t			*forks;
	sem_t			*msg;
	t_vars			v;
	unsigned long	start;
	int				is_dead;
}	t_philo;

#endif
