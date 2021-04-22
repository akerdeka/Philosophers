#include "list.h"

t_philo	*new_philo(size_t i)
{
	t_philo	*new;

	new = ft_xmalloc(sizeof(t_philo));
	new->id = i;
	new->is_alive = 1;
	new->next = NULL;
	new->prev = NULL;
	new->eated = 0;
	new->fork = 0;
	return (new);
}
