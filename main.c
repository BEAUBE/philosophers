/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:28:32 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/11 08:28:34 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (parsing(ac - 1, av + 1, &data))
	{
		printf("Error\n");
		return (1);
	}
	ft_init(&data);
	destroy_mutex(data);
	return (0);
}
