/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:01:22 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/02 21:52:05 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_start_time(t_d *d)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	d->start_usec = start_time.tv_usec;
	d->start_sec = start_time.tv_sec;
}
