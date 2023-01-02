/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:23:52 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/02 20:39:41 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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
		if (ft_isdigit(av[arg][i]))
			i++;
		else
			return (0);
		if (!av[arg][i])
			arg++;
	}
	return (1);
}

void	ft_values(int ac, char **av, t_d *d)
{
	ft_limited(ac, d);
	d->phi_nbr = ft_atoi(av[1]);
	d->death_time = ft_atoi(av[2]);
	d->meal_time = ft_atoi(av[3]);
	d->sleep_time = ft_atoi(av[4]);
	if (d->limited)
		d->meal_nbr = ft_atoi(av[5]);
}

void	ft_parsing(int ac, char **av, t_d *d)
{
	if (ft_onlydigits(ac, av))
		ft_values(ac, av, d);
	else
		write(1, "Error\n", 7);
}
