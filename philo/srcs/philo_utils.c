/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:27:13 by hcremers          #+#    #+#             */
/*   Updated: 2022/04/21 12:42:05 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	smart_printer(int id, char *string, t_data *struc)
{
	pthread_mutex_lock(&struc->freedom_of_speech);
	if (struc->is_everybody_alive)
		printf("%lld	%d %s\n", r_time(struc), id + 1, string);
	pthread_mutex_unlock(&struc->freedom_of_speech);
}

void	end_threads(t_data *struc)
{
	int	i;

	i = 0;
	while (i < struc->guests)
	{
		pthread_join(struc->philo[i]->thread_id, NULL);
		pthread_mutex_destroy(&struc->forks[i]);
		free(struc->philo[i]);
		i++;
	}
	pthread_mutex_destroy(&struc->freedom_of_speech);
	free(struc->forks);
	free(struc->philo);
	free(struc);
}
