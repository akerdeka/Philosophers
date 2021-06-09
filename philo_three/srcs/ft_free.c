/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:34:09 by akerdeka          #+#    #+#             */
/*   Updated: 2021/06/09 10:34:10 by akerdeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	ft_free(t_param *p)
{
	size_t	i;

	i = 0;
	while (p->philosophers && i < p->nb_of_philo)
	{
		kill(p->philosophers->fork, SIGKILL);
		free(p->philosophers);
		p->philosophers = p->philosophers->next;
		i++;
	}
}
