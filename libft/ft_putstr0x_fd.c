/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr0x_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:10:51 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/24 17:13:52 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr0x_fd(char *s, int fd, int *j)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (fd, "(null)", 6);
		*j = *j + 5;
		return ;
	}
	ft_putstr_fd("0x", 1, j);
	while (s[i])
	{
		write(fd, &s[i], 1);
		*j = *j + 1;
		i++;
	}
}
