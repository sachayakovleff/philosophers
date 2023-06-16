/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:34:21 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/10 17:56:30 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

void	ft_putnbrbaseup(size_t nb, int *d)
{
	int			i;
	char		*str;
	const char	*hex = "0123456789ABCDEF";
	const int	length = ft_countpf(nb);

	i = length - 1;
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return ;
	while (i >= 0)
	{
		str[i] = hex[nb % 16];
		nb /= 16;
		i--;
	}
	str[length] = '\0';
	ft_putstr_fd(str, 1, d);
	free(str);
}

void	ft_getstring(char *str, va_list args, int *i)
{
	if (str[0] == 's')
		ft_putstr_fd(va_arg(args, char *), 1, i);
	else if (str[0] == 'c')
		ft_putchar_fd(va_arg(args, int), 1, i);
	else if (str[0] == 'd' || str[0] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, i);
	else if (str[0] == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1, i);
	else if (str[0] == 'X')
		ft_putnbrbaseup(va_arg(args, unsigned int), i);
	else if (str[0] == '%')
		ft_putchar_fd('%', 1, i);
	else
	{
		ft_putchar_fd('%', 1, i);
		ft_putchar_fd(str[0], 1, i);
	}
}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int		i;
	int		*count;
	int		res;

	i = 0;
	res = 0;
	count = &res;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			ft_getstring(str + i, args, count);
		}
		else
			ft_putchar_fd(str[i], 1, count);
		i++;
	}
	return (res);
}
