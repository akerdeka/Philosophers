#include "../philo_one.h"

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
		if ((unsigned long)(cur_t.tv_sec * 1000 + cur_t.tv_usec / 1000) - \
			t->philo_stamp > (t->param->time_to_[Die]))
			t->is_alive = 0;
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
	int				rc;
	size_t			t;
	struct timeval	curt;

	t = 0;
	gettimeofday(&curt, NULL);
	p->timestamp = curt.tv_sec * 1000 + curt.tv_usec / 1000;
	pthread_mutex_init(&p->write, NULL);
	p->eat_end = 0;
	p->check_dead = 0;
	while (t < p->nb_of_philo)
	{
		p = swap_philo(p, t);
		gettimeofday(&curt, NULL);
		p->philosophers->philo_stamp = curt.tv_sec * 1000 + curt.tv_usec / 1000;
		rc = pthread_create(&pid, NULL, th_philo, p->philosophers);
		usleep(1000);
		t++;
	}
	pthread_join(pid, NULL);
	pthread_mutex_destroy(&p->write);
	ft_free(p);
	return ;
}
