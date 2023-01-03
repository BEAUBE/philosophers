/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:50:16 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/03 16:47:37 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_atoi(char *nptr)
{
	int i;
	long long int	result;
	int minus;

	minus = 1;
	result = 0;
	i = 0;
	while (nptr[i])
		result = result * 10 + nptr[i++] - '0';
	if (result < -2147483647 || result > 2147483647)
		return (-1);
	return (result);
}
