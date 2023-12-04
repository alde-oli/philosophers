/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:49:26 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/04 06:32:41 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMINGS_H
# define TIMINGS_H

#include "philosophers.h"

typedef struct s_timings
{
	int	die;
	int	eat;
	int	sleep;
	int	nb_meals;
}	t_timings;

t_timings	 get_timings(char **av);
int			check_timings(t_timings timings);

#endif
