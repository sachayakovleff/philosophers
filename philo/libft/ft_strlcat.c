/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:41:22 by marvin            #+#    #+#             */
/*   Updated: 2022/11/14 14:09:57 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			j;
	const size_t	dstlen = ft_strlen(dst);
	const size_t	srclen = ft_strlen(src);

	j = size;
	while (*dst)
	{
		dst++;
		if (j > 0)
			j--;
	}
	while (*src && j > 1)
	{
		*dst++ = *src++;
		j--;
	}
	*dst = '\0';
	if (size > dstlen)
		return (dstlen + srclen);
	return (size + srclen);
}
