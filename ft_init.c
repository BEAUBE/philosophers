/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:56:33 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/10 16:41:13 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo_data(t_main *main)
{
	int	tmp;

	tmp = 0;
	pthread_mutex_init(&main->philo[0].m_fork, NULL);
	while (tmp < main->d.phi_nbr - 1)
	{
		tmp++;
		pthread_mutex_init(&main->philo[tmp].m_fork, NULL);
		pthread_mutex_init(&main->philo[tmp].m_death, NULL);
		pthread_mutex_init(&main->philo[tmp].m_start_prev_meal, NULL);
		pthread_mutex_init(&main->philo[tmp].m_id_philo, NULL);
		main->philo[tmp].m_next_fork = &main->philo[tmp - 1].m_fork;
		main->philo[tmp].d = &main->d;
//		printf("tmp = %i \n", tmp);
	}
	main->philo[0].m_next_fork = &main->philo[main->d.phi_nbr - 1].m_fork;
	pthread_mutex_init(&main->philo[0].m_death, NULL);
	pthread_mutex_init(&main->philo[0].m_start_prev_meal, NULL);
	pthread_mutex_init(&main->philo[0].m_id_philo, NULL);
	main->philo[0].d = &main->d;
//	printf("tmp = 0 \n");
}

void	ft_init(t_main *main)
{
	int	tmp;
	int	phinbr;
	pthread_t	tchecker;

	phinbr = main->d.phi_nbr;
	tmp = main->d.phi_nbr;
	init_philo_data(main);
	ft_start_time(&main->d);
	while (phinbr)
	{
		phinbr--;
		pthread_create(&main->philo[phinbr].id_thread, NULL, &ft_philo, &main->philo[phinbr]);
	}
	pthread_create(&tchecker, NULL, &checker, main);
	while (tmp)
	{
		tmp--;
		pthread_join(main->philo[tmp].id_thread, NULL);
	}
}
