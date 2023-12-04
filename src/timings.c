/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:51:32 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/04 14:05:38 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_timings	get_timings(char **av, int ac)
{
	t_timings	timings;

	timings.die = ft_atoi(av[2]);
	timings.eat = ft_atoi(av[3]);
	timings.sleep = ft_atoi(av[4]);
	if (ac == 5)
		timings.nb_meals = -1;
	else
		timings.nb_meals = ft_atoi(av[5]);
	return (timings);
}

int	check_timings(t_timings timings)
{
	if (timings.die < 0 || timings.eat < 0 || timings.sleep < 0
		|| (timings.nb_meals < 0 && timings.nb_meals != -1))
	{
		printf("Error: timings must be positive integers\n");
		return (1);
	}
	return (0);
}
