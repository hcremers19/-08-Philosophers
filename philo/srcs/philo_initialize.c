/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:55:23 by hcremers          #+#    #+#             */
/*   Updated: 2022/04/22 14:26:51 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*live(t_philo *philo)
{
	pthread_mutex_init(&philo->struc->forks[philo->id], NULL);
	if (philo->id % 2)
		powernap(5000);
	while (philo->struc->is_everybody_alive)
	{
		pthread_mutex_lock(&philo->struc->forks[philo->id]);
		smart_printer(philo->id, "has taken a fork", philo->struc);
		pthread_mutex_lock(&philo->struc->forks[(philo->id + 1)
			% philo->struc->guests]);
		smart_printer(philo->id, "has taken a fork", philo->struc);
		smart_printer(philo->id, "is eating", philo->struc);
		if (philo->struc->max_meals > 0)
			philo->struc->max_meals--;
		philo->last_meal = a_time();
		powernap(philo->struc->tte);
		pthread_mutex_unlock(&philo->struc->forks[philo->id]);
		pthread_mutex_unlock(&philo->struc->forks[(philo->id + 1)
			% philo->struc->guests]);
		smart_printer(philo->id, "is sleeping", philo->struc);
		powernap(philo->struc->tts);
		smart_printer(philo->id, "is thinking", philo->struc);
	}
	return (NULL);
}

void	init_struc_2(char **argv, t_data *struc)
{
	struc->error = 0;
	struc->guests = ft_atoi(struc, argv[1]);
	struc->ttd = ft_atoi(struc, argv[2]) * 1000;
	struc->tte = ft_atoi(struc, argv[3]) * 1000;
	struc->tts = ft_atoi(struc, argv[4]) * 1000;
	struc->bigbang = a_time();
	struc->is_everybody_alive = 1;
	struc->did_everybody_eat = 0;
	pthread_mutex_init(&struc->freedom_of_speech, NULL);
}

void	init_struc(int argc, char **argv, t_data *struc)
{
	int	temp;

	init_struc_2(argv, struc);
	if (argc == 6)
	{
		temp = ft_atoi(struc, argv[5]);
		if (temp == -1)
			temp--;
		struc->max_meals = temp * struc->guests;
	}
	else
		struc->max_meals = -1;
	struc->philo = (t_philo **)malloc(sizeof(t_philo *) * struc->guests);
	if (!struc->philo)
		return ;
	struc->forks
		= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * struc->guests);
	if (!struc->forks)
		return ;
}

void	init_philos(t_data *struc)
{
	int	i;

	i = 0;
	while (i < struc->guests)
	{
		struc->philo[i] = (t_philo *)malloc(sizeof(t_philo));
		struc->philo[i]->struc = struc;
		struc->philo[i]->id = i;
		struc->philo[i]->last_meal = a_time();
		pthread_create(&struc->philo[i]->thread_id,
			NULL, (void *)&live, struc->philo[i]);
		i++;
	}
}
