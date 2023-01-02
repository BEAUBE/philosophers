/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:08:03 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/02 20:41:10 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_main	main;

	ft_parsing(ac, av, &main.d);
	(void)ac;
	(void)av;
	return (0);
}

/*
	printf("phi_nbr = %i, death_time = %i, meal_time = %i, sleep_time = %i (%i[%i])",
			main.d.phi_nbr, main.d.death_time, main.d.meal_time, main.d.sleep_time, main.d.limited, ac);
	if (main.d.limited)
		printf(", meal_nbr = %i", main.d.meal_nbr);
	printf(" \n");
*/
