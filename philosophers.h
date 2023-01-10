/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:01:24 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/10 16:25:28 by ajoliet          ###   ########.fr       */
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
	pthread_mutex_t	m_write;
	pthread_mutex_t	m_start_sec;
	pthread_mutex_t	m_start_usec;
	pthread_mutex_t	m_death_time;
	pthread_mutex_t	m_meal_time;
	pthread_mutex_t	m_sleep_time;
	pthread_mutex_t	m_meal_nbr;
	pthread_mutex_t	m_limited;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_id_dead_philo;
	pthread_mutex_t	m_id_phi_tmp;
	int				start_sec;
	int 			start_usec;
	int 			phi_nbr;
	int	 			death_time;
	int				meal_time;
	int				sleep_time;
	int				meal_nbr;
	int				limited;
	int 			parsvalid;
	int				dead;
	int				id_dead_philo;
}	t_d;

typedef struct s_philo
{
	t_d				*d;
	pthread_t		id_thread;
	pthread_mutex_t	m_fork;
	pthread_mutex_t *m_next_fork;
	pthread_mutex_t	m_death;
	pthread_mutex_t	m_start_prev_meal;
	pthread_mutex_t m_id_philo;
	int				id_philo;
	int				death;
	int				start_prev_meal;
}	t_philo;

typedef struct	s_main
{
	t_philo	philo[1024];
	t_d		d;
}	t_main;

void	*ft_philo(void *ptr);
void 	*checker(void *arg);
void	ft_start_time(t_d *d);
void	ft_parsing(int ac, char **av, t_d *d);
void	ft_init(t_main *main);
void	philo_printf(int id_phi, char action, t_d *d);
int		ft_onlydigits(int ac, char **av);
int		ft_atoi(char *nptr);
int		gettime(t_d *d);
int		get_mutex_data(int *var, pthread_mutex_t *mutex);

#endif
