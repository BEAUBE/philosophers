/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:23:52 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/03 17:41:32 by ajoliet          ###   ########.fr       */
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

int	ft_onlydigits(int ac, char **av)
{
	int arg;
	int	i;

	arg = 1;
	i = 0;
	if (ac == 1)
		return (0);
	while (arg < ac && av[arg][i])
	{
		if (av[arg][i] >= '0' && av[arg][i] <= '9')
			i++;
		else
			return (0);
		if (!av[arg][i])
			arg++;
	}
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
		d->death_time = ft_atoi(av[2]);
		d->meal_time = ft_atoi(av[3]);
		d->sleep_time = ft_atoi(av[4]);
	}
	if (d->limited)
		d->meal_nbr = ft_atoi(av[5]);
	if (verifyvalues(d))
		return (1);
	return (0);
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
}
