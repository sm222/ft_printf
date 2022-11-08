/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:00:16 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/08 14:58:17 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_of_x(unsigned long int nb, int base)
{
	int			size;

	size = 0;
	while (nb)
	{
		size++;
		nb /= base;
	}
	return (size);
}

char	*ft_utob(unsigned long int nb, int base)
{
	char		*hex_table;
	char		*result;
	int			i;

	i = size_of_x(nb, base);
	if (nb == 0)
		i++;
	hex_table = HEX_TABLE;
	result = ft_calloc(i, sizeof(char));
	if (!result)
		return (NULL);
	while (i--)
	{
		result[i] = hex_table[nb % base];
		nb /= 16;
	}
	return (result);
}
