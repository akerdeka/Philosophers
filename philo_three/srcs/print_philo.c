/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:34:03 by akerdeka          #+#    #+#             */
/*   Updated: 2021/06/09 10:34:04 by akerdeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	print_philo(t_philo *p, int action)
{
	struct timeval	current_time;
	long int		actual;

	sem_wait(p->param->write);
	gettimeofday(&current_time, NULL);
	actual = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	if (action == Eat)
		printf("%ld %zu is eating\n", actual - p->param->timestamp, p->id);
	else if (action == Fork)
		printf("%ld %zu has take a fork\n", actual - p->param->timestamp, p->id);
	else if (action == Sleep)
		printf("%ld %zu is sleeping\n", actual - p->param->timestamp, p->id);
	else if (action == Think)
		printf("%ld %zu is thinking\n", actual - p->param->timestamp, p->id);
	else if (action == Die)
	{
		printf("%ld %zu is dead !\n", actual - p->param->timestamp, p->id);
		p->param->check_dead = 1;
		exit(3);
	}
	sem_post(p->param->write);
}
