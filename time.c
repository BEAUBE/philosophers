/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:01:22 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/06 14:10:23 by ajoliet          ###   ########.fr       */
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

int	gettime(long long start_sec, int start_usec)
{
	struct	timeval	current_time;
	int	time_since_start;

	gettimeofday(&current_time, NULL);
	time_since_start = (current_time.tv_sec - start_sec) * 1000 +
			(current_time.tv_usec - start_usec) / 1000;
	return (time_since_start);
}
