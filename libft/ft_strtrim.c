/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:42:54 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/19 16:15:19 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int	ft_check(char s1, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_count(const char *s1, const char *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (ft_check(s1[i], set))
			count++;
		i++;
	}
	return (count);
}

void	ft_setchar(char *str, const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		if (ft_check(s1[j], set))
		{
			str[i] = s1[j];
			i++;
		}
		j++;
	}
	str[i] = '\0';
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		length;
	char	*str;

	if (!s1)
		return (NULL);
	length = ft_count(s1, set);
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	ft_setchar(str, s1, set);
	return (str);
}
