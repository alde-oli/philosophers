/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:38:24 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/07 23:06:18 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
	t_philo			philo;
	static int		i = 0;
	sem_t			*forks;
	pid_t			pid;

	forks = sem_open("forks", O_CREAT, 0644, nb_philo / 2);
	if (forks == SEM_FAILED)
		return (1);
	sem_unlink("forks");
	philo.v = sim_vars;
	while (i < nb_philo)
	{
		printf("coucou\n");
		philo.id = i + 1;
		pid = fork();
		if (pid == 0)
			return (philo_routine(&philo, forks, nb_philo));
		else if (pid < 0)
			return (1);
		i++;
	}
	while (waitpid(-1, NULL, 0))
		;
	sem_close(forks);
	return (0);
}
