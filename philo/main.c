/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:55:48 by hcremers          #+#    #+#             */
/*   Updated: 2022/11/10 11:59:13 by hcremers         ###   ########.fr       */
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
	if (init_struc(argc, argv, struc))
		return (1);
	if (recheck_args(struc))
		return (1);
	if (init_philos(struc))
		return (1);
	check_death_loop(struc);
	end_threads(struc);
	return (0);
}
