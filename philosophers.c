/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:10 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/06 17:48:23 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philo *philo, int id_phi)
{
	int time;

	pthread_mutex_lock(philo->m_next_fork);
	pthread_mutex_lock(&philo->m_fork);
	time = gettime(philo->d);
	printf("%i (time_since_start) %i (id_phi) has taken a fork\n", time, id_phi); 
	printf("%i %i is eating\n", time, id_phi);
	usleep(get_mutex_data(&philo->d->meal_time, &philo->d->m_meal_time));
	pthread_mutex_unlock(&philo->m_fork);
	pthread_mutex_unlock(philo->m_next_fork);
}
/*
void	ft_sleep(t_philo, int id_phi)
{

}
*/
void	routine(int id_phi, t_philo *philo)
{
	if (id_phi % 2)
		usleep(get_mutex_data(&philo->d->meal_time, &philo->d->m_meal_time) / 2);
	ft_eat(philo, id_phi);
//	ft_sleep();
//	ft_think();
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
