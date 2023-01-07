/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:10 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/07 16:15:58 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_eat(t_philo *philo, int id_phi)
{
	int time;

	pthread_mutex_lock(philo->m_next_fork);
	pthread_mutex_lock(&philo->m_fork);
	time = gettime(philo->d);
	pthread_mutex_lock(&philo->d->m_write);
	printf("%i %i has taken a fork\n", time, id_phi); 
	printf("%i %i is eating\n", time, id_phi);
	pthread_mutex_unlock(&philo->d->m_write);
	philo->start_prev_meal = time;
/*	if (get_mutex_data(&philo->d->meal_time, &philo->d->m_meal_time) 
			> get_mutex_data(&philo->d->death_time, &philo->d->m_death_time))
		usleep(get_mutex_data(&philo->d->death_time, &philo->d->m_death_time));
	else*/
		usleep(get_mutex_data(&philo->d->meal_time, &philo->d->m_meal_time));
	pthread_mutex_unlock(&philo->m_fork);
	pthread_mutex_unlock(philo->m_next_fork);
	return (1);
}

int	ft_sleep(t_philo *philo, int id_phi)
{
	int time;

	time = gettime(philo->d);
	pthread_mutex_lock(&philo->d->m_write);
	printf("%i %i is sleeping\n", time, id_phi);
	pthread_mutex_unlock(&philo->d->m_write);
	usleep(get_mutex_data(&philo->d->sleep_time, &philo->d->m_sleep_time));
	return (1);
}

int	ft_think(t_philo *philo, int id_phi)
{
	int	time;

	time = gettime(philo->d);
	pthread_mutex_lock(&philo->d->m_write);
	printf("%i %i is thinking\n", time, id_phi);
	pthread_mutex_unlock(&philo->d->m_write);
	return (1);
}

void	routine(int id_phi, t_philo *philo)
{
	int	nbr_meal;

	nbr_meal = 0;
	while (1)
	{
		if (id_phi % 2)
			usleep(get_mutex_data(&philo->d->meal_time, &philo->d->m_meal_time) / 2);
		if (!ft_eat(philo, id_phi))
			break ;
		nbr_meal++;
		if (!ft_sleep(philo, id_phi))
			break ;
		if (!ft_think(philo, id_phi))
			break ;
		if (get_mutex_data(&philo->d->limited, &philo->d->m_limited) && 
			get_mutex_data(&philo->d->meal_nbr, &philo->d->m_meal_nbr) == nbr_meal)
			break ;
	}
}

void	*ft_philo(void *arg)
{
	static int	id_phi_tmp;
	int id_phi;
	t_philo	*philo;

	id_phi = id_phi_tmp;
	id_phi_tmp++;
	philo = (t_philo *)arg;
	routine(id_phi, philo);
	return (arg);
}

/*
	printf("id_phi_nbr = %i \n", id_phi_nbr);
	printf("fork = %i \n", philo->fork);
	printf("&fork = %p \n", &fork);
	printf(" \n");
	sleep(id_phi_nbr);
*/
