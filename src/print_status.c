/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:31:32 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/04 11:45:03 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_fork(int name)
{
	printf("Philosopher %d has taken a fork\n", name);
}

void	print_eat(int name)
{
	printf("Philosopher %d is eating\n", name);
}

void	print_sleep(int name)
{
	printf("Philosopher %d is sleeping\n", name);
}

void	print_think(int name)
{
	printf("Philosopher %d is thinking\n", name);
}

void	print_dead(int name)
{
	printf("Philosopher %d died\n", name);
}
