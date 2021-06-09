/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:33:29 by akerdeka          #+#    #+#             */
/*   Updated: 2021/06/09 10:33:30 by akerdeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

void	ft_eat(t_philo *p)
{
	struct timeval	current_time;

	if (p->param->nb_of_philo == 1)
	{
		sem_wait(p->param->fork);
		print_philo(p, Fork);
		usleep(p->param->time_to_[Die] * 1000);
		sem_post(p->param->fork);
		return ;
	}
	sem_wait(p->param->fork);
	sem_wait(p->param->fork);
	print_philo(p, Fork);
	print_philo(p, Fork);
	print_philo(p, Eat);
	p->eated++;
	sem_wait(p->death);
	gettimeofday(&current_time, NULL);
	p->philo_stamp = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	sem_post(p->death);
	if (p->eated == p->param->nb_must_eat)
		p->param->eat_end++;
	usleep(p->param->time_to_[Eat] * 1000);
	sem_post(p->param->fork);
	sem_post(p->param->fork);
}

void	ft_sleep(t_philo *p)
{
	print_philo(p, Sleep);
	usleep(p->param->time_to_[Sleep] * 1000);
}
