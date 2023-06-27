/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:29:16 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/11 16:19:55 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *) s;
	if (c > 256)
		return (str);
	while (*str != c)
	{
		if (*str == 0)
			return (0);
		str++;
	}
	return (str);
}
