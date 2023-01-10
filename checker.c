/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:40:32 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/10 16:02:31 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*checker(void *arg)
{
	t_main	*main;
	int i;

	i = 0;
	main = (t_main *)arg;
	while (!get_mutex_data(&main->d.dead, &main->d.m_dead))
	{
		if ((gettime(&main->d) - get_mutex_data(&main->philo[i].start_prev_meal, 
										&main->philo[i].m_start_prev_meal))
			> get_mutex_data(&main->d.death_time, &main->d.m_death_time))
			{
				pthread_mutex_lock(&main->d.m_dead);
				pthread_mutex_lock(&main->d.m_id_dead_philo);
				main->d.dead = 1;
				main->d.id_dead_philo = main->philo[i].id_philo;
				pthread_mutex_unlock(&main->d.m_dead);
				pthread_mutex_unlock(&main->d.m_id_dead_philo);
			}
	}
	pthread_mutex_lock(&main->d.m_id_dead_philo);
	printf("%i %i is fucking dead", gettime(&main->d), main->d.id_dead_philo);
	pthread_mutex_unlock(&main->d.m_id_dead_philo);
	return (arg);
}
