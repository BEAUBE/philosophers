/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:10 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/05 16:38:25 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//vim afr

void	*ft_philo(void *arg)
{
	static int	id_phi_nbr_tmp;
	int id_phi_nbr;
	t_philo	*philo;

	id_phi_nbr = id_phi_nbr_tmp;
	id_phi_nbr_tmp++;
	philo = (t_philo *)arg;
	return (arg);
}

/*
	printf("id_phi_nbr = %i \n", id_phi_nbr);
	printf("fork = %i \n", philo->fork);
	printf("&fork = %p \n", &fork);
	printf(" \n");
	sleep(id_phi_nbr);
*/
