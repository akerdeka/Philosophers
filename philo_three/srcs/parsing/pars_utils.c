/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:34:23 by akerdeka          #+#    #+#             */
/*   Updated: 2021/06/09 10:34:24 by akerdeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo_three.h"

long	ft_atol(const char *str)
{
	long	i;
	long	neg;
	long	res;

	i = 0;
	neg = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (neg == 1)
		res = res * -1;
	return (res);
}

int	ft_isalldigit(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (!(c[i] >= 48 && c[i] <= 57))
		{
			printf("Error : only numbers are accepted !\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	checker(long to_check)
{
	if (to_check > INT_MAX || to_check < 1)
	{
		printf("Error : not a valid number !\n");
		return (-1);
	}
	return (1);
}

void	*ft_xmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(1);
	return (ptr);
}

t_param	*swap_philo(t_param *p, size_t i)
{
	while (p->philosophers->id != i + 1)
		p->philosophers = p->philosophers->next;
	return (p);
}
