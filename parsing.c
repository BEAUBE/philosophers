/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:23:52 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/06 16:02:46 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_limited(int ac, t_d *d)
{
	if (ac == 5)
		d->limited = 0;
	else if (ac == 6)
		d->limited = 1;
	else
		return (0);
	return (1);
}

int	verifyvalues(t_d *d)
{
	if (d->phi_nbr <= 0)
		return (0);
	if (d->death_time <= 0)
		return (0);
	if (d->meal_time <= 0)
		return (0);
	if (d->sleep_time <= 0)
		return (0);
	return (1);
}

int	ft_values(int ac, char **av, t_d *d)
{
	if (ft_limited(ac, d))
	{
		d->phi_nbr = ft_atoi(av[1]);
		d->death_time = ft_atoi(av[2]) * 1000;
		d->meal_time = ft_atoi(av[3]) * 1000;
		d->sleep_time = ft_atoi(av[4]) * 1000;
	}
	if (d->limited)
		d->meal_nbr = ft_atoi(av[5]);
	if (verifyvalues(d))
		return (1);
	return (0);
}

void	ft_init_mutex_d(t_d *d)
{
	pthread_mutex_init(&d->m_write, NULL);
	pthread_mutex_init(&d->m_time, NULL);
	pthread_mutex_init(&d->m_death_time, NULL);
	pthread_mutex_init(&d->m_meal_time, NULL);
	pthread_mutex_init(&d->m_sleep_time, NULL);
	pthread_mutex_init(&d->m_meal_nbr, NULL);
	pthread_mutex_init(&d->m_limited, NULL);
}

void	ft_parsing(int ac, char **av, t_d *d)
{
	if (ft_onlydigits(ac, av))
	{
		if (ft_values(ac, av, d))
			d->parsvalid = 1;
		else
		{
			d->parsvalid = 1;
			write(1, "Error\n", 7);
		}
	}
	else
	{
		d->parsvalid = 0;
		write(1, "Error\n", 7);
	}
	ft_init_mutex_d(d);
}
