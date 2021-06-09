/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:33:23 by akerdeka          #+#    #+#             */
/*   Updated: 2021/06/09 10:33:24 by akerdeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

static void	create_sem(t_param *p)
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

void	*th_brain(void *p)
{
	t_philo			*t;
	struct timeval	cur_t;

	t = p;
	while (t->param->check_dead == 0)
	{
		gettimeofday(&cur_t, NULL);
		if (t->is_alive == 0)
			print_philo(t, Die);
		sem_wait(t->death);
		if ((unsigned long)(cur_t.tv_sec * 1000 + cur_t.tv_usec / 1000) - \
			t->philo_stamp > (t->param->time_to_[Die]))
			t->is_alive = 0;
		sem_post(t->death);
		if (t->param->eat_end == t->param->nb_of_philo)
			break ;
		usleep(3000);
	}
	return (NULL);
}

void	*th_philo(void *p)
{
	int			rc;
	t_philo		*t;
	pthread_t	brain;

	t = p;
	create_sem(t->param);
	rc = pthread_create(&brain, NULL, th_brain, p);
	while (t->param->check_dead == 0)
	{
		if (t->param->eat_end == t->param->nb_of_philo)
			break ;
		ft_eat(t);
		if (t->param->eat_end == t->param->nb_of_philo || \
			t->param->nb_of_philo == 1)
			break ;
		ft_sleep(t);
		if (t->param->eat_end == t->param->nb_of_philo)
			break ;
		print_philo(t, Think);
	}
	pthread_join(brain, NULL);
	return (NULL);
}

void	create_threads(t_param *p)
{
	pthread_t		pid;
	static size_t	t = -1;
	struct timeval	curt;

	gettimeofday(&curt, NULL);
	p->timestamp = curt.tv_sec * 1000 + curt.tv_usec / 1000;
	sem_unlink("/write");
	p->write = sem_open("/write", O_CREAT, 0, 1);
	sem_unlink("/fork");
	p->fork = sem_open("/fork", O_CREAT, 0, p->nb_of_philo);
	p->eat_end = 0;
	p->check_dead = 0;
	while (++t < p->nb_of_philo)
	{
		p = swap_philo(p, t);
		gettimeofday(&curt, NULL);
		p->philosophers->philo_stamp = curt.tv_sec * 1000 + curt.tv_usec / 1000;
		pthread_create(&pid, NULL, th_philo, p->philosophers);
		usleep(1000);
	}
	pthread_join(pid, NULL);
	ft_free(p);
	return ;
}
