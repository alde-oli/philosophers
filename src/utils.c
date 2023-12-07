/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:03:49 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/06 15:24:47 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *s);

int	init_forks_and_philo(t_philo **philo, pthread_mutex_t **forks,
							int nb_philo, t_vars timings)
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
									t_vars sim_vars)
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
		philo[i].left_f = &forks[i];
		philo[i].right_f = &forks[(i + 1) % nb_philo];
		philo[i].v = sim_vars;
		i++;
	}
	return (philo);
}

t_vars	get_timings(char **av, int ac)
{
	t_vars	timings;

	timings.t_die = ft_atoi(av[2]);
	timings.t_eat = ft_atoi(av[3]);
	timings.t_sleep = ft_atoi(av[4]);
	if (ac == 5)
		timings.nb_meals = -1;
	else
		timings.nb_meals = ft_atoi(av[5]);
	return (timings);
}

void	clear_forks(pthread_mutex_t *forks, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
		pthread_mutex_destroy(&forks[i++]);
	free(forks);
}

int	ft_atoi(char *s)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		nb = nb * 10 + s[i] - '0';
		i++;
	}
	return (nb);
}
