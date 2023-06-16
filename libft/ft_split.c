/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:29:56 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/12 18:09:29 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_getal(char const *s, char c, size_t i, int ftnb)
{
	size_t	count;

	count = 0;
	if (ftnb == 0)
	{
		while (s[i])
		{
			if (s[i] != c)
			{
				count++;
				i += ft_getal(&s[i], c, 0, 1);
			}
			else
				i++;
		}
	}
	else
	{
		while (s[i] && s[i] != c)
		{
			i++;
			count++;
		}
	}
	return (count);
}

char	*ft_setword(char *str, const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_free(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_setstr(char **array, char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			array[j] = malloc(((ft_getal(&s[i], c, 0, 1) + 1)) * sizeof(char));
			if (array[j] == NULL)
			{
				free(s);
				return (ft_free(array, j));
			}
			array[j] = ft_setword(array[j], &s[i], c);
			j++;
			i += ft_getal(&s[i], c, 0, 1);
		}
		else
			i++;
	}
	array[j] = NULL;
	free(s);
	return (array);
}

char	**ft_split(char *s, char c)
{
	char	**array;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] == c)
		{
			free(s);
			return (NULL);
		}
		i++;
	}
	if (s == NULL)
		return (NULL);
	array = malloc((ft_getal(s, c, 0, 0) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	return (ft_setstr(array, s, c));
}
