/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:42:48 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/07 21:55:38 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*overwatch_routine(void *philo_p);
static int	do_cycle(t_philo *philo);

void	*philo_routine(void *philosopher)
{
	t_philo				*philo;

	philo = (t_philo *)philosopher;
	philo->start = get_cur_time();
	usleep(!(philo->id % 2) * 5);
	pthread_create(&philo->overwatch, NULL, overwatch_routine, philosopher);
	if (philo->left_f == philo->right_f)
		while (1)
			if (philo->is_dead)
				break ;
	do_cycle(philo);
	if (!philo->is_dead)
		printf("philosopher %d survived\n", philo->id);
	pthread_join(philo->overwatch, NULL);
	return (NULL);
}

static void	*overwatch_routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	while (philo->v.nb_meals && !philo->is_dead)
	{
		if (philo->v.last_meal + philo->v.t_die <= get_cur_time())
			philo->is_dead = 1;
		pls_wait(1);
	}
	if (philo->is_dead)
		display_action(philo->id, " died\n", philo->start);
	return (NULL);
}

static int	do_cycle(t_philo *philo)
{
	pthread_mutex_lock(philo->left_f);
	if (philo->is_dead)
		return (pthread_mutex_unlock(philo->left_f));
	display_action(philo->id, " has taken a fork\n", philo->start);
	pthread_mutex_lock(philo->right_f);
	if (philo->is_dead)
		return (pthread_mutex_unlock(philo->left_f)
			+ pthread_mutex_unlock(philo->right_f));
	display_action(philo->id, " has taken a fork\n", philo->start);
	philo->v.last_meal = get_cur_time();
	display_action(philo->id, " is eating\n", philo->start);
	pls_wait(philo->v.t_eat);
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	philo->v.nb_meals--;
	if (philo->is_dead)
		return (0);
	display_action(philo->id, " is sleeping\n", philo->start);
	pls_wait(philo->v.t_sleep);
	if (!philo->is_dead && philo->v.nb_meals)
	{
		display_action(philo->id, " is thinking\n", philo->start);
		return (do_cycle(philo));
	}
	return (0);
}
