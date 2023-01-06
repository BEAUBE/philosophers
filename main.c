/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:08:03 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/06 16:54:56 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_main	main;

	ft_parsing(ac, av, &main.d);
	printf("parsvalid = %i \n", main.d.parsvalid);
	if (main.d.parsvalid)
	{
		ft_init(&main);
	}
	return (0);
}

//		ft_start_time(&main.d);
/*
	printf("phi_nbr = %i, death_time = %i, meal_time = %i, sleep_time = %i (%i[%i])",
			main.d.phi_nbr, main.d.death_time, main.d.meal_time, main.d.sleep_time, main.d.limited, ac);
	if (main.d.limited)
		printf(", meal_nbr = %i", main.d.meal_nbr);
	printf(" \n");
*/

//printf("start_time : sec = %i, usec = %i \n", main.d.start_sec, main.d.start_usec);
