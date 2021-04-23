#ifndef PHILO_THREE_H
# define PHILO_THREE_H

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
# include <sys/types.h>
# include <signal.h>

# define STR_INT_MIN "-2147483648"

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
	size_t			nb_of_param;
}			t_param;

int		parsing(int ac, char **av, t_param *p);

void	create_threads(t_param *p);
void	print_philo(t_philo *p, int action);

int		ft_eat(t_philo *p);
void	ft_sleep(t_philo *p);
void	create_sem(t_param *p);

long	ft_atol(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_itoa(int n);
int		ft_isalldigit(char *c);
int		checker(long to_check);
t_param	*swap_philo(t_param *p, size_t i);
void	ft_free(t_param *p);

#endif
