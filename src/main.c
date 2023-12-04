/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:31:26 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/04 14:07:12 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	setup_and_run_sim(int nb_philo, t_timings timings);

int	main(int ac, char **av)
{
	t_timings	timings;

	if (ac != 6 && ac != 5)
	{
		printf("Usage: ./philosophers number_of_philosophers");
		printf(" time_to_die time_to_eat time_to_sleep");
		printf(" [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	timings = get_timings(av, ac);
	if (check_timings(timings))
		return (1);
	return (setup_and_run_sim(ft_atoi(av[1]), timings));
}

static int	setup_and_run_sim(int nb_philo, t_timings timings)
{
	pthread_mutex_t	*forks;
	t_philo			*philo;
	int				i;

	if (init_forks_and_philo(&philo, &forks, nb_philo, timings))
		return (1);
	i = 0;
	while (i < nb_philo)
	{
		philo[i].last_meal = get_cur_time();
		pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]);
		pthread_create(&philo[i].tracker, NULL, tracker_routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		pthread_join(philo[i].tracker, NULL);
		i++;
	}
	return (0);
}
