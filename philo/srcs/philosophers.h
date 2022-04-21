/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:56:14 by hcremers          #+#    #+#             */
/*   Updated: 2022/04/21 13:59:07 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
// # include "../wraloc/wraloc.h"

typedef struct s_philo
{
	int					id;
	long long			last_meal;
	struct s_data		*struc;
	pthread_t			thread_id;
}	t_philo;

typedef struct s_data
{
	int					guests;
	int					ttd;
	int					tte;
	int					tts;
	int					max_meals;
	long				bigbang;
	int					is_everybody_alive;
	int					did_everybody_eat;
	int					error;
	t_philo				**philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		freedom_of_speech;
}	t_data;

void					check_death_loop(t_data *struc);
int						check_args(int argc, char **argv);
int						recheck_args(t_data *struc);
long long				a_time(void);
long long				r_time(t_data *struc);
void					powernap(long long naptime);
void					smart_printer(int id, char *string, t_data *struc);
void					*live(t_philo *philo);
void					init_struc(int argc, char **argv, t_data *struc);
void					init_philos(t_data *struc);
void					end_threads(t_data *struc);

/* libft */

int						ft_atoi(t_data *struc, const char *str);
int						ft_isdigit(int c);
void					ft_putstr_fd(char *str, int fd);

#endif