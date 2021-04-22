#include "list.h"

t_philo	*new_philo(size_t i)
{
	t_philo	*new;

	new = ft_xmalloc(sizeof(t_philo));
	new->id = i;
	new->fork_used = NULL;
	new->is_alive = 1;
	new->next = NULL;
	new->prev = NULL;
	new->eated = 0;
	return (new);
}

t_fork	*new_fork(size_t i)
{
	t_fork	*new;

	new = ft_xmalloc(sizeof(t_fork));
	new->id = i;
	pthread_mutex_init(&new->m_fork, NULL);
	return (new);
}
