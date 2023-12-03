/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:40:39 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/02 11:40:39 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_STATUS_H
# define PRINT_STATUS_H

#include "philosophers.h"

void	print_eat(int name);
void	print_think(int name);
void	print_sleep(int name);
void	print_dead(int name);

#endif