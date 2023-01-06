/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:16:17 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/06 17:16:22 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_mutex_data(int *var, pthread_mutex_t *mutex)
{
	int tmp;
 
	pthread_mutex_lock(mutex);
	tmp = *var;
	pthread_mutex_unlock(mutex);
	return (tmp);
}
