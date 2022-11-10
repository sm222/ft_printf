/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:00:16 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/10 09:14:55 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_of_x(unsigned long long nb, int base)
{
	int	size;

	size = 0;
	while (nb)
	{
		size++;
		nb /= base;
	}
	return (size);
}

char	*ft_ulltoa(unsigned long long nb, int base)
{
	char		*result;
	int			i;

	i = size_of_x(nb, base);
	if (nb == 0)
		i++;
	result = ft_calloc(i + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (i--)
	{
		result[i] = HEX_TABLE[nb % base];
		nb /= base;
	}
	return (result);
}
