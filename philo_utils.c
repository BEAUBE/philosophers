/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:16:17 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/10 11:33:33 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_printf(int id_phi, char action, t_d *d)
{
	int time;

    time = gettime(d);
    pthread_mutex_lock(&d->m_write);
    if (action == 'f')
        printf("%i %i has taken a fork\n", time, id_phi);
    if (action == 'e')
        printf("%i %i is eating\n", time, id_phi);
    if (action == 's')
        printf("%i %i is sleeping\n", time, id_phi);
    if (action == 't')
        printf("%i %i is thinking\n", time, id_phi);
    pthread_mutex_unlock(&d->m_write);
}

int	get_mutex_data(int *var, pthread_mutex_t *mutex)
{
	int tmp;
 
	pthread_mutex_lock(mutex);
	tmp = *var;
	pthread_mutex_unlock(mutex);
	return (tmp);
}
