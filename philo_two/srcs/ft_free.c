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
