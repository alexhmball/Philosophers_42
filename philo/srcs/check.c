/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 00:47:54 by baller            #+#    #+#             */
/*   Updated: 2022/10/08 20:44:04 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_check(t_philo *reaper)
{
	unsigned long	dead;

	dead = get_now() - reaper->last_ate;
	if (dead > reaper->info->time_to_die)
	{
		pthread_mutex_lock(&reaper->global->death_mutex);
		dead = get_now() - reaper->global->start;
		if (!reaper->global->death)
			printf("%s%4ldms  Philo %3d %s\n", RED, dead, reaper->id, "is dead");
		reaper->global->death = 1;
		pthread_mutex_unlock(&reaper->global->death_mutex);
		reaper->alive = 0;
		return (0);
	}
	return (1);
}

int	check_global_death(t_philo *reaper)
{
	pthread_mutex_lock(&reaper->global->death_mutex);
	if (!reaper->global->death)
	{
		pthread_mutex_unlock(&reaper->global->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&reaper->global->death_mutex);
	return (0);
}

int	check_fork(t_philo *philo, int temp)
{
	pthread_mutex_lock(philo->left_fork);
	if (!*philo->left || *philo->left == philo->id)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	if (*philo->left)
	{
		temp = *philo->left;
		*philo->left = 0;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	if (!*philo->right || *philo->right == philo->id)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		*philo->left = temp;
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	*philo->right = 0;
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

int	check_last_fork(t_philo *philo, int temp)
{
	pthread_mutex_lock(philo->right_fork);
	if (!*philo->right || *philo->right == philo->id)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	if (*philo->right)
	{
		temp = *philo->right;
		*philo->right = 0;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	if (!*philo->left || *philo->left == philo->id)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		*philo->right = temp;
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	*philo->left = 0;
	pthread_mutex_unlock(philo->left_fork);
	return (1);
}

void	set_forks(t_philo *philo)
{
	if (philo->id == philo->info->total)
	{
		pthread_mutex_lock(philo->right_fork);
		*philo->right = philo->id;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		*philo->left = philo->id;
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		*philo->left = philo->id;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		*philo->right = philo->id;
		pthread_mutex_unlock(philo->right_fork);
	}
}
