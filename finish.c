/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:20:16 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/11 08:20:34 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	destroy_mutex(t_data data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data.m_nb_philo_ate);
	pthread_mutex_destroy(&data.m_print);
	pthread_mutex_destroy(&data.m_is_philo_dead);
	while (i < data.philo_nbr)
	{
		pthread_mutex_destroy(&data.philo[i].m_last_meal_ts);
		pthread_mutex_destroy(&data.philo[i].m_fork);
		i++;
	}
	return (0);
}
