/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:07:48 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/04 22:57:17 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_eat(t_philo *philo);

void	*tracker_routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	while (philo->timings.nb_meals && !philo->is_dead)
	{
		if (philo->last_meal + philo->timings.die <= get_cur_time())
			philo->is_dead = 1;
		usleep(500);
	}
	if (philo->is_dead)
		//print_dead(philo->id);
		printf("Philosopher %d died at %llu !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n", philo->id, get_cur_time());
	return (NULL);
}

void	*philo_routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;

	while (philo->timings.nb_meals && !philo->is_dead)
	{
		print_think(philo->id);
		if (!philo->is_dead)
			philo_eat(philo);
		if (!philo->is_dead)
		{
			//print_sleep(philo->id);
			printf("Philosopher %d is sleeping at %llu\n", philo->id, get_cur_time());
			usleep(philo->timings.sleep * 1000);
		}
	}
	return (NULL);
}

static void	philo_eat(t_philo *philo)
{
	if (philo->left_fork == philo->right_fork)
		while (1)
			if (philo->is_dead)
				return ;
	if (philo->id % 2)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	//print_fork(philo->id);
	printf("Philosopher %d has taken his first fork at %llu\n", philo->id, get_cur_time());
	if (philo->id % 2)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	//print_fork(philo->id);
	printf("Philosopher %d has taken his second fork at %llu\n", philo->id, get_cur_time());
	if (!philo->is_dead)
	{
		philo->last_meal = get_cur_time();
		//print_eat(philo->id);
		printf("Philosopher %d is eating at %llu\n", philo->id, get_cur_time());
		philo->timings.nb_meals -= 1;
		usleep(philo->timings.eat * 1000);
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	printf("Philosopher %d has dropped his forks at %llu\n", philo->id, get_cur_time());
}
