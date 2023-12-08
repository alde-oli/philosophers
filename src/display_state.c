/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:07:15 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/08 14:11:44 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_nbrlen(int n);
static char	*ft_itoa(int n);

int	display_action(t_philo *philo, char *action)
{
	char		*time;
	char		*id_s;

	time = ft_itoa(get_cur_time() - philo->start);
	pthread_mutex_lock(philo->msg);
	if (philo->is_dead && !*philo->one_died)
		*philo->one_died = 1;
	else if (*philo->one_died)
	{
		free(time);
		philo->is_dead = 1;
		return (pthread_mutex_unlock(philo->msg));
	}
	id_s = ft_itoa(philo->id);
	printf("%s %s%s", time, id_s, action);
	free(time);
	free(id_s);
	pthread_mutex_unlock(philo->msg);
	return (0);
}

static int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_nbrlen(n) + 1));
	if (!str)
		return (NULL);
	i = ft_nbrlen(n);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
