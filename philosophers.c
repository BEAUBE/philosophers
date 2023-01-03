/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:10 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/03 17:35:00 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_philo(void *ptr)
{
	static int	id_phi_nbr_tmp;
	int id_phi_nbr;

	id_phi_nbr = id_phi_nbr_tmp;
	id_phi_nbr_tmp++;
	printf("oui, id_phi_nbr = %i \n", id_phi_nbr);
	sleep(1);
	printf("oui, id_phi_nbr = %i \n", id_phi_nbr);
	return (ptr);
}

