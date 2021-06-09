/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:33:26 by akerdeka          #+#    #+#             */
/*   Updated: 2021/06/09 10:33:27 by akerdeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

void	ft_free(t_param *p)
{
	size_t	i;

	i = 0;
	sem_close(p->fork);
	sem_close(p->philosophers->death);
	while (i < p->nb_of_philo)
	{
		free(p->philosophers);
		p->philosophers = p->philosophers->next;
		i++;
	}
}
