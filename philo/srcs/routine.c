/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:43:34 by baller            #+#    #+#             */
/*   Updated: 2022/10/19 14:24:33 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_message(char *s, t_philo *philo, char *c)
{
	unsigned long	time;

	pthread_mutex_lock(&philo->global->death_mutex);
	time = get_now() - philo->global->start;
	if (!philo->global->death)
	{
		printf("%s%4ldms  Philo %3d %s\n", c, time, philo->id, s);
		pthread_mutex_unlock(&philo->global->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->global->death_mutex);
	return (0);
}

int	eating(t_philo *philo)
{
	int				forks;

	if (philo->id == philo->info->total)
		forks = check_last_fork(philo, 0);
	else
		forks = check_fork(philo, 0);
	if (forks)
	{
		print_message("has taken a fork", philo, CYAN);
		print_message("has taken a fork", philo, CYAN);
		philo->alive = print_message("is eating", philo, GREEN);
		ft_usleep(philo->info->time_to_eat, philo);
		philo->last_ate = get_now();
		set_forks(philo);
		if (philo->info->must_eat)
			philo->amount_to_eat--;
		if (philo->alive && philo->amount_to_eat)
			return (1);
		return (-1);
	}
	return (0);
}

void	*philo(void *philos)
{
	t_philo	*philo;
	int		ate;

	philo = philos;
	if (philo->info->total == 1)
	{
		print_message("has taken a fork", philo, CYAN);
		ft_usleep(philo->info->time_to_die + 10, philo);
	}
	if (philo->id % 2 == 0)
		ft_usleep(philo->info->time_to_eat, philo);
	while (philo->alive && philo->amount_to_eat)
	{
		ate = eating(philo);
		if (ate == -1)
			break ;
		if (ate)
		{
			print_message("is sleeping", philo, YELLOW);
			ft_usleep(philo->info->time_to_sleep, philo);
			philo->alive = print_message("is thinking", philo, MAGENTA);
		}
		ft_usleep(1, philo);
	}
	return (0);
}
