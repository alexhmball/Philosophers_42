/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:53:41 by baller            #+#    #+#             */
/*   Updated: 2022/10/08 00:41:55 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_my_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	error_message(long r, int s)
{
	if (r * s > INT_MAX || r * s < INT_MIN)
		return (0);
	return (1);
}

//function that converts a string to an integer
int	ft_atoi(const char *str)
{
	int		s;
	long	r;

	r = 0;
	s = 1;
	if (!is_my_digit(str))
		return (0);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s *= -1;
		str++;
		break ;
	}
	while (*str >= '0' && *str <= '9')
	{
		r *= 10;
		r += *str - '0';
		str++;
		if (!error_message(r, s))
			return (0);
	}
	return (r * s);
}
