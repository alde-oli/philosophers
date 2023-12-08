/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:03:49 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/08 15:57:17 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_atoi(char *s);

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
