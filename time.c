/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:01:22 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/06 16:43:33 by ajoliet          ###   ########.fr       */
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

int	gettime(t_d *d)
{
	struct	timeval	current_time;
	int	time_since_start;
	int start_sec;
	int start_usec;

	start_usec = get_mutex_data(&d->start_usec, &d->m_start_usec);
	start_sec = get_mutex_data(&d->start_sec, &d->m_start_sec);
	gettimeofday(&current_time, NULL);
	time_since_start = (current_time.tv_sec - start_sec) * 1000 +
			(current_time.tv_usec - start_usec) / 1000;
	return (time_since_start);
}
