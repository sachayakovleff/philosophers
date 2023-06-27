/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:39:29 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/11 16:11:00 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			str = &((char *)s)[i];
		i++;
	}
	if (c == '\0')
		str = &((char *)s)[i];
	return (str);
}
