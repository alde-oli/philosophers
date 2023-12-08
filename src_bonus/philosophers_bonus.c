/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:38:24 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/08 15:46:07 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/philosophers_bonus.h"
#include <semaphore.h>

static int		killall(t_philo *philo, int *pids, int nb_philo);
static t_philo	*setup_philo(int nb_philo, t_vars sim_vars);
static int		setup_and_run_sim(int nb_philo, t_vars sim_vars);

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
	t_philo		*philo;
	int			i;
	int			*pids;

	i = 0;
	philo = setup_philo(nb_philo, sim_vars);
	pids = malloc(sizeof(int) * nb_philo);
	while (i < nb_philo)
	{
		pids[i] = fork();
		if (!pids[i])
		{
			philo_routine(&philo[i], nb_philo == 1);
			killall(philo, pids, nb_philo);
			return (0);
		}
		else if (pids[i] < 0)
			return (killall(philo, pids, nb_philo));
		i++;
	}
	i = 0;
	while (i < nb_philo)
		waitpid(pids[i++], NULL, 0);
	return (0);
}

static t_philo	*setup_philo(int nb_philo, t_vars sim_vars)
{
	t_philo	*philo;
	int		i;
	sem_t	*forks;
	sem_t	*msg;

	i = 0;
	philo = malloc(sizeof(t_philo) * nb_philo);
	forks = sem_open("forks", O_CREAT, 0644, nb_philo / 2);
	msg = sem_open("msg", O_CREAT, 0644, 1);
	sem_unlink("forks");
	sem_unlink("msg");
	while (i < nb_philo)
	{
		philo[i].v = sim_vars;
		philo[i].id = i + 1;
		philo[i].forks = forks;
		philo[i].msg = msg;
		i++;
	}
	return (philo);
}

static int	killall(t_philo *philo, int *pids, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
		kill(pids[i++], SIGKILL);
	sem_close(philo->forks);
	sem_close(philo->msg);
	free(philo);
	free(pids);
	return (1);
}
