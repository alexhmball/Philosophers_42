/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:53:37 by baller            #+#    #+#             */
/*   Updated: 2022/10/08 00:37:49 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(int size, char **str)
{
	int	*args;

	args = create_int_arr(str, size);
	if (!args)
		return ;
	init(args, size);
}

int	*create_int_arr(char **av, int size)
{
	int	*args;
	int	i;

	i = 0;
	args = (int *)malloc(size * sizeof(int));
	if (!args)
		return (NULL);
	while (i < size)
	{
		args[i] = ft_atoi(av[i]);
		if (args[i] <= 0)
		{
			printf("error\nInvalid input\n");
			free (args);
			return (NULL);
		}
		i++;
	}
	return (args);
}
