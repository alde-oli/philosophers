/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:31:26 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/03 21:31:26 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_timings	timings;
	if (ac != 6)
	{
		printf("Usage: ./philosophers [number_of_philosophers]");
		printf(" [time_to_die] [time_to_eat] [time_to_sleep]");
		printf(" [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	timings = get_timings(av);
	if (check_timings(timings));
		return (1);
	return (run_simulation(ft_atoi(av[1]), timings));
}

int	run_simulation(int nb_philo, t_timings timings)
{
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!forks)
		return (1);
	i = 0;
	while (i < nb_philo)
		pthread_mutex_init(&forks[i++], NULL);
	philosophers = init_philosophers(nb_philo, forks);
	if (!philosophers)
		return (1);
	i = 0;
	while (i < nb_philo)
	{
		pthread_create(&philosophers[i].thread, NULL, &philosopher_routine, &philosophers[i]);
		i++;
	}
	return (0);
}

t_philosopher	*init_philosophers(int nb_philo, pthread_mutex_t *forks)
{
	t_philosopher	*philosophers;
	int				i;

	philosophers = malloc(sizeof(t_philosopher) * nb_philo);
	if (!philosophers)
		return (NULL);
	i = 0;
	while (i < nb_philo)
	{
		philosophers[i].id = i + 1;
		philosophers[i].left_fork = &forks[i];
		philosophers[i].right_fork = &forks[(i + 1) % nb_philo];
		i++;
	}
	return (philosophers);
}