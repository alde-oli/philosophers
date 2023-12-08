/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:38:24 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/08 15:47:56 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	add_elem(t_philo **philo, int *one_died,
				pthread_mutex_t *msg, int nb_philo);

static int	setup_and_run_sim(int nb_philo, t_vars sim_vars);

int	main(int ac, char **av)
{
	t_vars	sim_vars;

	if (ac != 6 && ac != 5)
	{
		printf("Usage: ./philosophers number_of_philosophers");
		printf(" time_to_die time_to_eat time_to_sleep");
		printf(" [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	sim_vars = get_timings(av, ac);
	if (sim_vars.t_die < 0 || sim_vars.t_eat < 0 || sim_vars.t_sleep < 0
		|| (sim_vars.nb_meals < 0 && sim_vars.nb_meals != -1))
	{
		printf("Error: invalid numbers\n");
		return (1);
	}
	return (setup_and_run_sim(ft_atoi(av[1]), sim_vars));
}

static int	setup_and_run_sim(int nb_philo, t_vars sim_vars)
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	t_philo			*philo;
	int				i;
	int				*one_died;

	pthread_mutex_init(&msg, NULL);
	one_died = malloc(sizeof(int));
	if (init_forks_and_philo(&philo, &forks, nb_philo, sim_vars))
		return (1);
	i = 0;
	add_elem(&philo, one_died, &msg, nb_philo);
	while (i < nb_philo)
	{
		philo[i].v.last_meal = get_cur_time();
		pthread_create(&philo[i].thread_p, NULL, philo_routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < nb_philo)
		pthread_join(philo[i++].thread_p, NULL);
	clear_forks(forks, nb_philo);
	free(one_died);
	free(philo);
	return (pthread_mutex_destroy(&msg));
}

static void	add_elem(t_philo **philo, int *one_died,
	pthread_mutex_t *msg, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		(*philo)[i].msg = msg;
		(*philo)[i].one_died = one_died;
		i++;
	}
}
