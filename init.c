/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:36:40 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/11 11:01:08 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_philo(pthread_mutex_t *next_fork, t_data *data, int i)
{
	data->philo[i].id = i;
	data->philo[i].data = data;
	pthread_mutex_init(&data->philo[i].m_fork, NULL);
	data->philo[i].m_next_fork = next_fork;
}

void	set_philos(t_data *data)
{
	int	i;

	i = 1;
	set_philo(NULL, data, 0);
	while (i < data->philo_nbr)
	{
		set_philo(&data->philo[i - 1].m_fork, data, i);
		i++;
	}
	data->philo[0].m_next_fork = &data->philo[i - 1].m_fork;
}

void	init_philos(t_data *data)
{
	int			i;
	pthread_t	p_checker;

	i = 0;
	data->nb_philo_ate = 0;
	data->is_philo_dead = 0;
	data->begin_ts = get_time_stamp();
	while (i < data->philo_nbr)
	{
		pthread_mutex_init(&data->philo[i].m_last_meal_ts, NULL);
		data->philo[i].last_meal_ts = data->begin_ts;
		pthread_create(&data->philo[i].thread, NULL, routine, &data->philo[i]);
		i++;
	}
	pthread_create(&p_checker, NULL, checker, data);
	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	pthread_join(p_checker, NULL);
}

void	init_mutex(t_data *data)
{
	pthread_mutex_init(&data->m_nb_philo_ate, NULL);
	pthread_mutex_init(&data->m_print, NULL);
	pthread_mutex_init(&data->m_is_philo_dead, NULL);
}

void	ft_init(t_data *data)
{
	set_philos(data);
	init_mutex(data);
	init_philos(data);
}
