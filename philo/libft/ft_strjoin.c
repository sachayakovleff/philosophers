/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:12:22 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/11 16:13:12 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char		*str;
	int			i;
	int			j;
	const int	k = ft_strlen(s1);
	const int	l = ft_strlen(s2);

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < k)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < l)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	str[i] = '\0';
	return (str);
}
