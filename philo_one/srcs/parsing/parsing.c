/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:33:06 by akerdeka          #+#    #+#             */
/*   Updated: 2021/06/09 10:33:07 by akerdeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo_one.h"

static void	create_philo(t_param *p, size_t i, t_philo *tmp, t_philo *first)
{
	tmp = p->philosophers;
	p->philosophers->next = new_philo(i);
	p->philosophers = p->philosophers->next;
	pthread_mutex_init(&p->philosophers->death, NULL);
	p->philosophers->prev = tmp;
	p->philosophers->next = first;
	first->prev = p->philosophers;
}

static void	set_id_philo(t_param *p)
{
	static size_t	i = 1;
	t_philo			*tmp;
	t_philo			*first;

	p->philosophers = new_philo(i);
	first = p->philosophers;
	p->philosophers->param = p;
	while (++i <= p->nb_of_philo)
	{
		if (i != p->nb_of_philo)
		{
			tmp = p->philosophers;
			p->philosophers->next = new_philo(i);
			p->philosophers = p->philosophers->next;
			p->philosophers->prev = tmp;
		}
		else
			create_philo(p, i, tmp, first);
		p->philosophers->param = p;
	}
	if (p->nb_of_philo > 1)
		p->philosophers = p->philosophers->next;
}

static void	set_id_fork(t_param *p)
{
	size_t	i;

	i = 0;
	while (++i <= p->nb_of_philo)
	{
		p->philosophers->fork_used = new_fork(i);
		if (p->nb_of_philo > 1)
			p->philosophers = p->philosophers->next;
	}
}

int	parsing(int ac, char **av, t_param *p)
{
	size_t	i;

	i = 0;
	while (++i < 5)
		if (checker(ft_atol(av[i])) == -1 || ft_isalldigit(av[i]))
			return (1);
	p->nb_of_philo = ft_atol(av[1]);
	p->time_to_[Die] = ft_atol(av[2]);
	p->time_to_[Eat] = ft_atol(av[3]);
	p->time_to_[Sleep] = ft_atol(av[4]);
	if (ac == 6)
	{
		if (checker(ft_atol(av[5])) == -1 || ft_isalldigit(av[5]))
			return (1);
		p->nb_must_eat = ft_atol(av[5]);
	}
	set_id_philo(p);
	set_id_fork(p);
	return (0);
}
