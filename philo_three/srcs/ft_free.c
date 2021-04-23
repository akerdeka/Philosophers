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
