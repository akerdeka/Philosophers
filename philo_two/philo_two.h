#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <semaphore.h>
# include "srcs/list_utils/list.h"

typedef enum e_time_to
{
	Die,
	Eat,
	Sleep,
	Think,
	Fork,
}			t_time_to;

typedef struct s_param
{
	bool			check_dead;
	size_t			nb_of_philo;
	size_t			time_to_[3];
	size_t			nb_must_eat;
	long int		timestamp;
	size_t			eat_end;
	t_philo			*philosophers;
	sem_t			*fork;
	sem_t			*write;
}			t_param;

int		parsing(int ac, char **av, t_param *p);

void	create_threads(t_param *p);
void	print_philo(t_philo *p, int action);

void	ft_eat(t_philo *p);
void	ft_sleep(t_philo *p);

long	ft_atol(const char *str);
int		ft_isalldigit(char *c);
int		checker(long to_check);
t_param	*swap_philo(t_param *p, size_t i);
void	ft_free(t_param *p);

#endif
