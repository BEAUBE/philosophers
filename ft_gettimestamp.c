/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettimestamp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:20:55 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/11 08:21:18 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned int	get_time_stamp(void)
{	
	struct timeval	value;

	gettimeofday(&value, NULL);
	return (value.tv_sec * 1000 + value.tv_usec / 1000);
}
