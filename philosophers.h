/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:33:26 by ajoliet           #+#    #+#             */
/*   Updated: 2023/01/11 13:57:59 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILO		1024

typedef struct s_philo
{
	int				id;
	int				nb_meal;
	int				meal_count;
	pthread_mutex_t	m_fork;
	pthread_mutex_t	*m_next_fork;
	pthread_t		thread;
	pthread_mutex_t	m_last_meal_ts;
	unsigned int	last_meal_ts;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int					philo_nbr;
	int					death_time;
	int					meal_time;
	int					sleep_time;
	int					max_meals;
	int					nb_philo_ate;
	int					is_philo_dead;
	unsigned int		begin_ts;
	pthread_mutex_t		m_is_philo_dead;
	pthread_mutex_t		m_print;
	pthread_mutex_t		m_nb_philo_ate;	
	t_philo				philo[MAX_PHILO];
}						t_data;

int				ft_atoi(char *str);
int				parsing(int ac, char **av, t_data *data);
int				destroy_mutex(t_data data);
int				stop_simu(t_data *data);
void			ft_init(t_data *data);
int				get_mutex_var(int *var, pthread_mutex_t *mutex);
unsigned int	get_time_stamp(void);
void			*routine(void *arg);
void			*checker(void *arg);
void			ft_say(char *str, t_philo *philo);
void			ft_one_philo(t_philo *philo);
void			increment_mutex_var(int *var, pthread_mutex_t *mutex);
void			take_fork(t_philo *philo, pthread_mutex_t *m_fork);
void			set_mtx_var(int *var, pthread_mutex_t *mtx, int val);

#endif
