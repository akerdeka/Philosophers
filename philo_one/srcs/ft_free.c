/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:32:51 by akerdeka          #+#    #+#             */
/*   Updated: 2021/06/09 10:32:52 by akerdeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	ft_free(t_param *p)
{
	size_t	i;

	i = 0;
	while (i < p->nb_of_philo)
	{
		free(p->philosophers->fork_used);
		free(p->philosophers);
		pthread_mutex_destroy(&p->philosophers->death);
		p->philosophers = p->philosophers->next;
		i++;
	}
}
