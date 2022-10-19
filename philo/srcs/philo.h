/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:53:30 by baller            #+#    #+#             */
/*   Updated: 2022/10/08 20:44:34 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define YELLOW "\x1b[33m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"

typedef struct s_info
{
	int				must_eat;
	unsigned long	time_to_die;
	unsigned long	time_to_sleep;
	unsigned long	time_to_eat;
	int				total;
	int				amount_to_eat;

}			t_info;

typedef struct s_global
{
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	*fork_mutex;
	pthread_t		*philos;
	int				*forks;
	unsigned long	start;
	int				death;
	t_info			*info;
}			t_global;

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	unsigned long	last_ate;
	int				*left;
	int				*right;
	int				alive;
	int				id;
	int				amount_to_eat;
	t_info			*info;
	t_global		*global;
}			t_philo;

typedef struct s_data
{
	t_philo			*philo;
	t_info			*info;
	t_global		*global;

}			t_data;

int				ft_atoi(const char *str);
int				*create_int_arr(char **av, int size);
void			parsing(int size, char **str);
void			init(int *args, int size);
void			init_data(t_info *info, t_global *global);
void			init_philo(t_philo *philo, t_global *global, int i);
void			malloc_everything(t_global *global, t_info *info, t_data *data);
void			*philo(void *philos);
int				ft_usleep(unsigned long sleep, t_philo *philo);
int				print_message(char *s, t_philo *philo, char *c);
void			create(t_data *data);
int				death_check(t_philo *reaper);
int				check_fork(t_philo *philo, int temp);
int				check_last_fork(t_philo *philo, int temp);
void			set_forks(t_philo *philo);
int				check_amount_ate(t_philo *philo);
int				is_dead(t_philo *philo);
int				check_global_death(t_philo *reaper);
unsigned long	get_now(void);

#endif