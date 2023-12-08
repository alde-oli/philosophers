/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:07:10 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/08 12:34:47 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# include "structs.h"

t_vars				get_timings(char **av, int ac);
int					init_forks_and_philo(t_philo **philo,
						pthread_mutex_t **forks, int nb_philo, t_vars timings);
t_philo				*init_philo(int nb_philo, pthread_mutex_t *forks,
						t_vars sim_vars);
void				clear_forks(pthread_mutex_t *forks, int nb_philo);
int					ft_atoi(char *s);
void				*philo_routine(void *philo);
int					display_action(t_philo *philo, char *action);
unsigned long long	get_cur_time(void);
void				pls_wait(unsigned long long time_ms);

#endif