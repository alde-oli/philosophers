/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:15:52 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/04 10:31:51 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philosophers.h"

int		init_forks_and_philo(t_philo **philo, pthread_mutex_t **forks,
			int nb_philo, t_timings timings);
t_philo	*init_philo(int nb_philo, pthread_mutex_t *forks,
			t_timings timings);

#endif
