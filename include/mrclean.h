/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrclean.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:38:07 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/04 10:38:36 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRCLEAN_H
# define MRCLEAN_H

# include "philosophers.h"

void	clear_forks(pthread_mutex_t *forks, int nb_philo);

#endif
