/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:34:12 by akerdeka          #+#    #+#             */
/*   Updated: 2021/06/09 10:34:13 by akerdeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	create_sem(t_param *p)
{
	char	*sem_name;
	char	*id;

	id = ft_itoa(p->philosophers->id);
	sem_name = ft_strjoin("/death_", id);
	sem_unlink(sem_name);
	p->philosophers->death = sem_open(sem_name, O_CREAT, 0, 1);
	free(sem_name);
	free(id);
	return ;
}
