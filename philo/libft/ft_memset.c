/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:32:54 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/09 12:33:43 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, unsigned long int n)
{
	char	*str;

	str = s;
	while (n != 0)
	{
		*str = (unsigned char) c;
		str++;
		n--;
	}
	return (s);
}
