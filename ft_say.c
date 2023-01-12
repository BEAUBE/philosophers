/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_say.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:21:41 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/11 08:24:00 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_say(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (!get_mutex_var(&philo->data->is_philo_dead,
			&philo->data->m_is_philo_dead))
		printf("%u %i %s\n", get_time_stamp()
			- philo->data->begin_ts, philo->id + 1, str);
	pthread_mutex_unlock(&philo->data->m_print);
}
