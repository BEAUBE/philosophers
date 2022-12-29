/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:08:03 by ajoliet           #+#    #+#             */
/*   Updated: 2022/12/29 15:53:41 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_main	main;

	ft_parsing(ac, av, &main.d);
	/*printf("phi_nbr = %i, death_time = %i, meal_time = %i, sleep_time = %i",
			main.d.phinbr, main.d.death_time, main.d.meal_time, main.d.sleep_time);
	if (main.limited)
		printf(", meal_nbr = %i", main.d.meal_nbr);
	printf(" \n ");*/
	(void)ac;
	(void)av;
	return (0);
}
