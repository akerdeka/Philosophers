#ifndef LIST_H
# define LIST_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
typedef struct s_param		t_param;
typedef struct s_fork		t_fork;

struct s_fork
{
	size_t			id;
	pthread_mutex_t	m_fork;
};

typedef struct s_philo		t_philo;

struct s_philo
{
	bool		is_alive;
	size_t		id;
	t_fork		*fork_used;
	t_philo		*prev;
	t_philo		*next;
	t_param		*param;
	size_t		eated;
	long int	philo_stamp;
};

t_philo	*new_philo(size_t i);
t_fork	*new_fork(size_t i);
void	*ft_xmalloc(size_t size);

#endif
