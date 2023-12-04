/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:07:51 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/04 11:21:58 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_forks_and_philo(t_philo **philo, pthread_mutex_t **forks,
							int nb_philo, t_timings timings)
{
	int	i;

	*forks = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!*forks)
		return (1);
	i = 0;
	while (i < nb_philo)
		pthread_mutex_init(&(*forks)[i++], NULL);
	i = 0;
	*philo = init_philo(nb_philo, *forks, timings);
	if (!*philo)
	{
		clear_forks(*forks, nb_philo);
		return (1);
	}
	return (0);
}

t_philo	*init_philo(int nb_philo, pthread_mutex_t *forks,
									t_timings timings)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * nb_philo);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % nb_philo];
		philo[i].timings = timings;
		i++;
	}
	return (philo);
}
