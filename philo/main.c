/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:55:48 by hcremers          #+#    #+#             */
/*   Updated: 2022/04/21 13:58:55 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	*struc;

	if (check_args(argc, argv))
		return (1);
	struc = (t_data *)malloc(sizeof(t_data));
	if (!struc)
		return (1);
	init_struc(argc, argv, struc);
	if (recheck_args(struc))
		return (1);
	init_philos(struc);
	check_death_loop(struc);
	end_threads(struc);
	return (0);
}
