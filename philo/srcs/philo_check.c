/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:08:17 by hcremers          #+#    #+#             */
/*   Updated: 2022/04/21 13:40:42 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_putstr_fd("Error: invalid argument(s)\n", 2);
				return (1);
			}
			else
				j++;
		}
		i++;
	}
	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		return (1);
	}
	return (0);
}

int	recheck_args(t_data *struc)
{
	if (struc->guests < 1 || struc->tte < 0 || struc->tts < 0
		|| struc->ttd < 0 || struc->max_meals < -1 || struc->guests > 250
		|| struc->error)
	{
		ft_putstr_fd("Error: invalid argument(s)\n", 2);
		free(struc->forks);
		free(struc->philo);
		free(struc);
		return (1);
	}
	else
		return (0);
}

int	check_death(t_philo *philo)
{
	if (!philo->struc->max_meals)
	{
		philo->struc->is_everybody_alive = 0;
		return (1);
	}
	if (a_time() - philo->last_meal >= philo->struc->ttd)
	{
		smart_printer(philo->id, "died", philo->struc);
		philo->struc->is_everybody_alive = 0;
		if (philo->struc->guests == 1)
			pthread_mutex_unlock(&philo->struc->forks[0]);
		return (1);
	}
	return (0);
}

void	check_death_loop(t_data *struc)
{
	int	i;

	i = 0;
	while (!check_death(struc->philo[i]))
	{
		i++;
		if (i == struc->guests)
			i = 0;
	}
}
