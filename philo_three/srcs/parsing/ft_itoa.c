/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:34:20 by akerdeka          #+#    #+#             */
/*   Updated: 2021/06/09 10:34:21 by akerdeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo_three.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*s;
	char			*d;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	s = (const char *)src;
	d = (char *)dest;
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

static char	*ft_strdup(const char *str)
{
	size_t		size;
	size_t		i;
	char		*dest;

	i = 0;
	size = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * size + 1);
	ft_memcpy(dest, str, size);
	return (dest);
}

char	*ft_itoa(int n)
{
	static char	buf[12] = {0};
	int			i;
	int			neg;

	i = 10;
	neg = 1;
	if (n == INT_MIN)
		return (ft_strdup(STR_INT_MIN));
	if (n < 0)
	{
		neg = -1;
		n = -n;
	}
	while (1)
	{
		buf[i--] = n % 10 + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	if (neg == -1)
		buf[i] = '-';
	if (neg == -1)
		return (ft_strdup(buf + i));
	return (ft_strdup(buf + 1 + i));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int			i;
	int			j;
	char		*str;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)ft_xmalloc(sizeof(char) * (i + j + 1));
	j = 0;
	str = ft_memcpy(str, s1, i);
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
