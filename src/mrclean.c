/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrclean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:37:09 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/04 10:37:33 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clear_forks(pthread_mutex_t *forks, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
		pthread_mutex_destroy(&forks[i++]);
	free(forks);
}
