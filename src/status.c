/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:31:32 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/02 11:31:32 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(int name)
{
	printf("Philosopher %d is eating\n", name);
}

void	sleep(int name)
{
	printf("Philosopher %d is sleeping\n", name);
}

void	think(int name)
{
	printf("Philosopher %d is thinking\n", name);
}

void	dead(int name)
{
	printf("Philosopher %d is dead\n", name);
}