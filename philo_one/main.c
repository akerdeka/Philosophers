/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:32:39 by akerdeka          #+#    #+#             */
/*   Updated: 2021/06/09 10:32:40 by akerdeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	main(int ac, char **av)
{
	t_param	p;

	if (ac != 5 && ac != 6)
		printf("Error, need 4 or 5 arguments\n");
	else
	{
		if (parsing(ac, av, &p) == 1)
			return (0);
		create_threads(&p);
	}
	pthread_mutex_unlock(&p.write);
	return (0);
}
