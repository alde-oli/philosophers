/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:49:26 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/03 21:49:26 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMINGS_H
# define TIMINGS_H

#include "philosophers.h"

typedef struct s_timings
{
    int die;
    int eat;
    int sleep;
    int nb_meals;
}   t_timings;

#endif
