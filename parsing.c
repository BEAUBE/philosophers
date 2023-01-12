/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:29:57 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/11 14:34:32 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parsing(int ac, char **av, t_data *data)
{
	if (!(ac == 4 || ac == 5))
		return (1);
	data->philo_nbr = ft_atoi(av[0]);
	if (data->philo_nbr < 1 || data->philo_nbr > MAX_PHILO)
		return (1);
	data->death_time = ft_atoi(av[1]);
	if (data->death_time < 1)
		return (1);
	data->meal_time = ft_atoi(av[2]);
	if (data->meal_time < 1)
		return (1);
	data->sleep_time = ft_atoi(av[3]);
	if (data->sleep_time < 1)
		return (1);
	if (ac == 5)
	{
		data->max_meals = ft_atoi(av[4]);
		if (data->max_meals <= 0)
			return (1);
	}
	else
		data->max_meals = -1;
	return (0);
}
