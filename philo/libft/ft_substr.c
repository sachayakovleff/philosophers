/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:17:29 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/10 17:59:31 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_setmalloc(const char *s, unsigned int start, size_t len)
{
	if (start > (size_t) ft_strlen(s) || !s || len == 0)
		return (malloc(sizeof(char)));
	if (len + start > (size_t) ft_strlen(s))
		return (malloc(sizeof(char) * ((size_t) ft_strlen(s) - start + 1)));
	return (malloc(sizeof(char) * (len + 1)));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	const size_t	k = (size_t) ft_strlen(s);

	str = ft_setmalloc(s, start, len);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && i + start < (size_t) k)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
