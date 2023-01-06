/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:50:16 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/06 20:30:45 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_onlydigits(int ac, char **av)
{
    int arg;
    int i;

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

int ft_atoi(char *nptr)
{
	int i;
	long long int	result;

	result = 0;
	i = 0;
	while (nptr[i])
		result = result * 10 + nptr[i++] - '0';
	if (result < -2147483647 || result > 2147483647)
		return (-1);
	return (result);
}
