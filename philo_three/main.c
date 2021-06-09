/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:33:58 by akerdeka          #+#    #+#             */
/*   Updated: 2021/06/09 10:33:59 by akerdeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	main(int ac, char **av)
{
	t_param	p;

	if (ac != 5 && ac != 6)
		printf("Error, need 4 or 5 arguments\n");
	else
	{
		p.nb_of_param = ac;
		if (parsing(ac, av, &p) == 1)
			return (0);
		create_threads(&p);
	}
	sem_post(p.write);
	sem_close(p.write);
	return (0);
}
