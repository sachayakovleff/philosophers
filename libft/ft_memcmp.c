/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:00:36 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/09 14:42:50 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*str1 > *str2)
			return (1);
		if (*str1 < *str2)
			return (-1);
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 != '\0')
		return (-1);
	else if (*str2 == '\0' && *str1 != '\0')
		return (1);
	else
		return (0);
}
