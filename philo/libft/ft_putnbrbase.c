/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:31:31 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/19 16:19:10 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_putnbrbase(size_t nb, int *d)
{
	int			i;
	char		*str;
	const char	*hex = "0123456789abcdef";
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
}
