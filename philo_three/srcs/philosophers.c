/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:34:06 by akerdeka          #+#    #+#             */
/*   Updated: 2021/06/09 10:34:07 by akerdeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	*th_brain(void *p)
{
	t_philo			*t;
	struct timeval	cur_t;

	t = p;
	while (t->param->check_dead == 0)
	{
		gettimeofday(&cur_t, NULL);
		if (t->eated == t->param->nb_must_eat)
			return (NULL);
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
		if (ft_eat(t) == 1)
			break ;
		ft_sleep(t);
		print_philo(t, Think);
	}
	pthread_join(brain, NULL);
	exit(0);
	return (NULL);
}

static void	create_fork(t_param *p)
{
	if (p->philosophers->fork == 0)
	{
		p->philosophers->fork = fork();
		if (p->philosophers->fork == 0)
		{
			th_philo(p->philosophers);
			exit(0);
		}
	}
}

static int	check(void)
{
	int	status;
	int	ret;

	ret = 0;
	status = 0;
	ret = waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == 3)
		return (1);
	if (ret <= 0)
		return (1);
	return (0);
}

void	create_threads(t_param *p)
{
	size_t			t;
	struct timeval	curt;

	t = -1;
	gettimeofday(&curt, NULL);
	p->timestamp = curt.tv_sec * 1000 + curt.tv_usec / 1000;
	sem_unlink("write");
	p->write = sem_open("write", O_CREAT, 0, 1);
	sem_unlink("fork");
	p->fork = sem_open("fork", O_CREAT, 0, p->nb_of_philo);
	while (++t < p->nb_of_philo)
	{
		p = swap_philo(p, t);
		gettimeofday(&curt, NULL);
		p->philosophers->philo_stamp = curt.tv_sec * 1000 + curt.tv_usec / 1000;
		create_fork(p);
		usleep(1000);
	}
	while (1)
		if (check())
			break ;
	sem_close(p->fork);
	ft_free(p);
	return ;
}
