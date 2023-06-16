/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countpf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:11:30 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/19 16:16:39 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_countpf(size_t nb)
{
	int	count;

	count = 0;
	while (nb > 0)
	{
		nb /= 16;
		count++;
	}
	return (count);
}
