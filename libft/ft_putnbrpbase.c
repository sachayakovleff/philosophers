/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrpbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:38:58 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/24 17:10:11 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_putstr0x_fd(char *s, int fd, int *j);

void	ft_putnbrpbase(size_t nb, int *d)
{
	int			i;
	char		*str;
	const char	*hex = "0123456789abcdef";
	const int	length = ft_countpf(nb);

	i = length - 1;
	if (nb == 0)
	{
		ft_putstr_fd("(nil)", 1, d);
		return ;
	}
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return ;
	if (nb == 0)
		str[0] = '0';
	while (i >= 0)
	{
		str[i] = hex[nb % 16];
		nb /= 16;
		i--;
	}
	str[length] = '\0';
	ft_putstr0x_fd(str, 1, d);
	free (str);
}
