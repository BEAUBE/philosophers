/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:24:37 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/11 13:57:47 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (!str[i])
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result *= 10;
		result += str[i] - '0';
		if (result > 2147483647)
			return (-1);
		i++;
	}
	return ((int)result);
}

void	increment_mutex_var(int *var, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*var += 1;
	pthread_mutex_unlock(mutex);
}

int	get_mutex_var(int *var, pthread_mutex_t *mutex)
{
	int	tmp;

	pthread_mutex_lock(mutex);
	tmp = *var;
	pthread_mutex_unlock(mutex);
	return (tmp);
}

void	set_mtx_var(int *var, pthread_mutex_t *mtx, int val)
{
	pthread_mutex_lock(mtx);
	*var = val;
	pthread_mutex_unlock(mtx);
}
