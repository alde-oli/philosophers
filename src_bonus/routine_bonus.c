/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:42:48 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/08 15:48:28 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/philosophers_bonus.h"

static void	*overwatch_routine(void *philo_p);
static int	do_cycle(t_philo *philo);

void	*philo_routine(void *philosopher, int is_lonely)
{
	t_philo				*philo;

	philo = (t_philo *)philosopher;
	philo->start = get_cur_time();
	philo->v.last_meal = philo->start;
	usleep(!(philo->id % 2) * philo->v.t_eat * 850);
	pthread_create(&philo->overwatch, NULL, overwatch_routine, philosopher);
	if (is_lonely)
		while (1)
			if (philo->is_dead && !pthread_join(philo->overwatch, NULL))
				break ;
	if (!is_lonely)
	{
		do_cycle(philo);
		pthread_join(philo->overwatch, NULL);
	}
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
		display_action(philo, " died\n");
	return (NULL);
}

static int	do_cycle(t_philo *philo)
{
	sem_wait(philo->forks);
	if (philo->is_dead)
		return (sem_post(philo->forks));
	display_action(philo, " has taken a fork\n");
	display_action(philo, " has taken a fork\n");
	philo->v.last_meal = get_cur_time();
	display_action(philo, " is eating\n");
	pls_wait(philo->v.t_eat);
	sem_post(philo->forks);
	philo->v.nb_meals--;
	if (philo->is_dead)
		return (0);
	display_action(philo, " is sleeping\n");
	pls_wait(philo->v.t_sleep);
	if (!philo->is_dead && philo->v.nb_meals)
	{
		display_action(philo, " is thinking\n");
		return (do_cycle(philo));
	}
	return (0);
}
