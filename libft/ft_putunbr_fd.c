/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:20:42 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/24 16:09:20 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include <stdio.h>

void	ft_putunbr_fd(unsigned int n, int fd, int *d)
{
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd, d);
		ft_putnbr_fd(n % 10, fd, d);
	}
	else
		ft_putchar_fd(n + '0', fd, d);
}
