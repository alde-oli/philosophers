/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:05:55 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/08 14:00:28 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/philosophers_bonus.h"

unsigned long long	get_cur_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}

void	pls_wait(unsigned long long time_ms)
{
	unsigned long long	start;
	int					sleep_time;

	start = get_cur_time();
	sleep_time = time_ms - 1;
	if (sleep_time > 0)
		usleep(sleep_time * 1000);
	while (get_cur_time() - start < time_ms)
		continue ;
}
