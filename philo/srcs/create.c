/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:31:24 by baller            #+#    #+#             */
/*   Updated: 2022/10/08 18:39:42 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	freedom(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->info->total)
		pthread_mutex_destroy(&data->global->fork_mutex[i++]);
	pthread_mutex_destroy(&data->global->death_mutex);
	free(data->global->forks);
	free(data->philo);
	free(data->global->philos);
	free(data->global->fork_mutex);
}

void	create(t_data *data)
{
	int	i;

	i = 0;
	data->global->start = get_now();
	while (i < data->info->total)
	{
		data->philo[i].last_ate = data->global->start;
		pthread_create(&data->global->philos[i], NULL, &philo, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->info->total)
		pthread_join(data->global->philos[i++], NULL);
	freedom(data);
}
