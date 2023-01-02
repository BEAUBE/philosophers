/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:01:24 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/01 14:55:18 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_d
{
	pthread_mutex_t m_start;
	pthread_mutex_t	m_d;
	int start_usec;
	int	start_sec;
	int phi_nbr;
	int death_time;
	int	meal_time;
	int	sleep_time;
	int	meal_nbr;
	int	limited;
}	t_d;

typedef struct s_philo
{
	pthread_t	id_thread;
	t_d	*d;
	int fork;
	int *next_fork;
}	t_philo;

typedef struct	s_main
{
	t_philo	philo[1024];
	t_d	d;
}	t_main;

void	ft_parsing(int ac, char **av, t_d *d);
int		ft_atoi(char *nptr);

#endif
