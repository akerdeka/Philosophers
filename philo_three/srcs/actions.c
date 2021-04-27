#include "../philo_three.h"

static int	sem_set(t_param *akerdekouille)
{
	sem_post(akerdekouille->fork);
	sem_post(akerdekouille->fork);
	return (1);
}

int	ft_eat(t_philo *p)
{
	struct timeval	current_time;

	if (p->param->nb_of_philo == 1)
	{
		sem_wait(p->param->fork);
		print_philo(p, Fork);
		usleep(p->param->time_to_[Die] * 1000);
		sem_post(p->param->fork);
		return (1);
	}
	sem_wait(p->param->fork);
	sem_wait(p->param->fork);
	print_philo(p, Fork);
	print_philo(p, Fork);
	print_philo(p, Eat);
	p->eated++;
	gettimeofday(&current_time, NULL);
	p->philo_stamp = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	usleep(p->param->time_to_[Eat] * 1000);
	if (p->eated == p->param->nb_must_eat)
		return (sem_set(p->param));
	sem_set(p->param);
	return (0);
}

void	ft_sleep(t_philo *p)
{
	print_philo(p, Sleep);
	usleep(p->param->time_to_[Sleep] * 1000);
}
