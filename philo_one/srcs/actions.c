#include "../philo_one.h"

void	ft_eat(t_philo *p)
{
	struct timeval	current_time;

	if (p->param->nb_of_philo == 1)
	{
		pthread_mutex_lock(&p->fork_used->m_fork);
		print_philo(p, Fork);
		usleep(p->param->time_to_[Die] * 1000);
		pthread_mutex_unlock(&p->fork_used->m_fork);
		return ;
	}
	pthread_mutex_lock(&p->prev->fork_used->m_fork);
	pthread_mutex_lock(&p->fork_used->m_fork);
	print_philo(p, Fork);
	print_philo(p, Fork);
	print_philo(p, Eat);
	p->eated++;
	gettimeofday(&current_time, NULL);
	p->philo_stamp = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	if (p->eated == p->param->nb_must_eat)
		p->param->eat_end++;
	usleep(p->param->time_to_[Eat] * 1000);
	pthread_mutex_unlock(&p->prev->fork_used->m_fork);
	pthread_mutex_unlock(&p->fork_used->m_fork);
}

void	ft_sleep(t_philo *p)
{
	print_philo(p, Sleep);
	usleep(p->param->time_to_[Sleep] * 1000);
}
