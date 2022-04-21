/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:34:43 by hcremers          #+#    #+#             */
/*   Updated: 2022/04/20 14:22:33 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	a_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

long long	r_time(t_data *struc)
{
	return ((a_time() - struc->bigbang) / 1000);
}

void	powernap(long long naptime)
{
	long long	napstart;

	napstart = a_time();
	while (1)
	{
		if ((a_time() - napstart) >= naptime)
			break ;
		usleep(50);
	}
}
