/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:19:54 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/14 14:20:34 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	ft_count(int n)
{
	int	res;

	res = 0;
	if (n < 0 && n != INT_MIN)
	{
		n *= -1;
		res++;
	}
	if (n == INT_MIN)
	{
		n = INT_MAX;
		res++;
	}
	while (n >= 10)
	{
		res++;
		n /= 10;
	}
	return (res + 1);
}

long int	ft_unsign(int n)
{
	long int	nb;

	if (n == INT_MIN)
		nb = (long int)INT_MAX + 1;
	else
		nb = n * -1;
	return (nb);
}

size_t	ft_getnb(int n, char *str)
{
	size_t	nb;

	if (n < 0)
	{
		nb = ft_unsign(n);
		str[0] = '-';
	}
	else
		nb = n;
	return (nb);
}

char	*ft_itoa(int n)
{
	char				*str;
	const unsigned int	length = ft_count(n);
	int					i;
	long int			nb;

	i = 0;
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (str);
	nb = ft_getnb(n, str);
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[length - i - 1] = nb % 10 + '0';
		i++;
		nb /= 10;
	}
	str[length] = '\0';
	return (str);
}
