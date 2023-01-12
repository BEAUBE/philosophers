/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:02:02 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/11 14:04:45 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_died(int id_dead_philo, t_data *data)
{
	pthread_mutex_lock(&data->m_print);
	printf("%u %i died\n", get_time_stamp() - data->begin_ts, id_dead_philo + 1);
	pthread_mutex_unlock(&data->m_print);
}

void	*checker(void *arg)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)arg;
	while (get_mutex_var(&data->nb_philo_ate, &data->m_nb_philo_ate)
		< data->philo_nbr && i < data->philo_nbr
		&& !get_mutex_var(&data->is_philo_dead, &data->m_is_philo_dead))
	{
		if (get_time_stamp()
			- get_mutex_var((int *)&data->philo[i].last_meal_ts,
				&data->philo[i].m_last_meal_ts)
			> (unsigned int)data->death_time)
		{
			set_mtx_var(&data->is_philo_dead,
				&data->m_is_philo_dead, 1);
			print_died(i, data);
		}
		i++;
		if (i == data->philo_nbr)
			i = 0;
	}
	return (arg);
}
