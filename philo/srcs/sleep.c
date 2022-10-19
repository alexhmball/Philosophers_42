/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:48:38 by baller            #+#    #+#             */
/*   Updated: 2022/10/08 19:33:12 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

int	ft_usleep(unsigned long sleep, t_philo *philo)
{
	unsigned long	start;

	start = get_now();
	while ((get_now() - start) < sleep)
	{
		if (!death_check(philo))
			return (0);
		usleep(1000);
	}
	return (1);
}
