/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:33:39 by baller            #+#    #+#             */
/*   Updated: 2022/10/08 19:04:08 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	malloc_everything(t_global *global, t_info *info, t_data *data)
{
	data->philo = (t_philo *)malloc(info->total * sizeof(t_philo));
	global->forks = (int *)malloc(info->total * sizeof(int));
	global->fork_mutex = (pthread_mutex_t *)malloc(info->total * \
	sizeof(pthread_mutex_t));
	global->philos = (pthread_t *)malloc(info->total * sizeof(pthread_t));
}

void	init_mutex(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->info->total)
	{
		if (pthread_mutex_init(&global->fork_mutex[i++], NULL) != 0)
			printf("Erorr\nMutex init failed\n");
	}
	if (pthread_mutex_init(&global->death_mutex, NULL) != 0)
		printf("Erorr\nMutex init failed\n");
}

void	init_philo(t_philo *philo, t_global *global, int i)
{
	philo->global = global;
	philo->info = global->info;
	philo->alive = 1;
	philo->id = i + 1;
	philo->amount_to_eat = 1;
	philo->last_ate = 0;
	if (global->info->must_eat)
		philo->amount_to_eat = global->info->amount_to_eat;
	philo->left = &global->forks[i];
	*philo->left = 900;
	philo->left_fork = &global->fork_mutex[i];
	if (philo->id == global->info->total)
	{
		philo->right = &global->forks[0];
		philo->right_fork = &global->fork_mutex[0];
	}
	else
	{
		philo->right = &global->forks[i + 1];
		philo->right_fork = &global->fork_mutex[i + 1];
	}
}

void	init_data(t_info *info, t_global *global)
{
	t_data	data;
	int		i;

	data.info = info;
	data.global = global;
	global->death = 0;
	malloc_everything(global, info, &data);
	init_mutex(global);
	i = 0;
	while (i < data.info->total)
	{
		init_philo(&data.philo[i], global, i);
		i++;
	}
	create(&data);
}

void	init(int *args, int size)
{
	t_info		info;
	t_global	global;

	info.total = args[0];
	info.time_to_die = args[1];
	info.time_to_eat = args[2];
	info.time_to_sleep = args[3];
	info.must_eat = 0;
	if (size == 5)
	{
		info.amount_to_eat = args[4];
		info.must_eat = 1;
	}
	global.info = &info;
	free(args);
	init_data(&info, &global);
}
