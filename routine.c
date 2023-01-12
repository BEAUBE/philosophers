/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:44:06 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/11 14:24:49 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(t_philo *philo, pthread_mutex_t *m_fork)
{
	pthread_mutex_lock(m_fork);
	ft_say("has taken a fork", philo);
}

void	ft_eat(t_philo *philo)
{
	take_fork(philo, &philo->m_fork);
	take_fork(philo, philo->m_next_fork);
	ft_say("is eating", philo);
	set_mtx_var((int *)&philo->last_meal_ts, &philo->m_last_meal_ts,
		get_time_stamp());
	usleep(philo->data->meal_time * 1000);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->m_fork);
	pthread_mutex_unlock(philo->m_next_fork);
}

void	ft_sleep(t_philo *philo)
{
	ft_say("is sleeping", philo);
	usleep(philo->data->sleep_time * 1000);
}

void	actions(t_philo *philo)
{
	while (stop_simu(philo->data))
	{
		ft_eat(philo);
		if (philo->meal_count == philo->data->max_meals)
			increment_mutex_var(&philo->data->nb_philo_ate,
				&philo->data->m_nb_philo_ate);
		if (get_mutex_var(&philo->data->nb_philo_ate,
				&philo->data->m_nb_philo_ate) == philo->data->philo_nbr)
			break ;
		ft_sleep(philo);
		if (get_mutex_var(&philo->data->nb_philo_ate,
				&philo->data->m_nb_philo_ate) == philo->data->philo_nbr)
			break ;
		ft_say("is thinking", philo);
		if (get_mutex_var(&philo->data->nb_philo_ate,
				&philo->data->m_nb_philo_ate) == philo->data->philo_nbr)
			break ;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->meal_count = 0;
	if (philo->data->philo_nbr == 1)
	{
		ft_one_philo(philo);
		return (arg);
	}
	if (philo->id % 2)
		usleep(500);
	actions(philo);
	return (arg);
}
