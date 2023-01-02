/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:56:33 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/03 00:06:45 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_test(void *ptr)
{
	//static int	nbrphitest;

	printf("oui\n");
	//nbrphitest += 1;
	//printf("test : %i", nbrphitest);
	return (ptr);
}

void	ft_init(t_main *main)
{
	int	tmp;

	tmp = main->d.phi_nbr;
	while (tmp)
	{
		tmp--;
		pthread_create(&main->philo[tmp].id_thread, NULL, &ft_test, &main->d);
	}
	tmp = main->d.phi_nbr;
	while (tmp)
	{
		tmp --;
		pthread_join(main->philo[tmp].id_thread, NULL);
	}
}
