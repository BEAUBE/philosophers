/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:44:45 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/11 10:53:17 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	stop_simu(t_data *data)
{
	if (get_mutex_var(&data->nb_philo_ate, &data->m_nb_philo_ate)
		< data->philo_nbr)
	{
		if (!get_mutex_var(&data->is_philo_dead, &data->m_is_philo_dead))
			return (1);
	}
	return (0);
}

void	ft_one_philo(t_philo *philo)
{
	take_fork(philo, &philo->m_fork);
	pthread_mutex_unlock(&philo->m_fork);
}
