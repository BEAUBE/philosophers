/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:23:52 by ajoliet           #+#    #+#             */
/*   Updated: 2022/12/29 17:32:07 by ajoliet          ###   ########.fr       */
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
	while (av[arg][i] && arg < ac)
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
	assigner les valeurs mais ca c'est rapide donc go
}

void	ft_parsing(int ac, char **av, t_d *d)
{
	ft_onlydigits(ac, av);
	ft_values(
}
