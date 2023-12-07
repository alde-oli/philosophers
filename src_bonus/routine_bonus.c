/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:42:48 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/07 23:06:49 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	*overwatch_routine(void *philo_p);
static int	do_cycle(t_philo *philo, sem_t *forks);

void	*philo_routine(t_philo *philo, sem_t *forks, int lonely)
{
	philo->is_dead = 0;
	philo->start = get_cur_time();
	philo->v.last_meal = get_cur_time();
	pthread_create(&philo->overwatch, NULL, overwatch_routine, philo);
	if (lonely == 1)
		while (1)
			if (philo->is_dead)
				return (1);
	do_cycle(philo, forks);
	if (!philo->is_dead)
		printf("philosopher %d survived\n", philo->id);
	pthread_join(philo->overwatch, NULL);
	return (0);
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

static int	do_cycle(t_philo *philo, sem_t *forks)
{
	sem_wait(forks);
	if (philo->is_dead)
		return (sem_post(forks));
	display_action(philo->id, " has taken a fork\n", philo->start);
	display_action(philo->id, " has taken a fork\n", philo->start);
	philo->v.last_meal = get_cur_time();
	display_action(philo->id, " is eating\n", philo->start);
	pls_wait(philo->v.t_eat);
	sem_post(forks);
	philo->v.nb_meals--;
	if (philo->is_dead)
		return (0);
	display_action(philo->id, " is sleeping\n", philo->start);
	pls_wait(philo->v.t_sleep);
	if (!philo->is_dead && philo->v.nb_meals)
	{
		display_action(philo->id, " is thinking\n", philo->start);
		return (do_cycle(philo, forks));
	}
	return (0);
}
